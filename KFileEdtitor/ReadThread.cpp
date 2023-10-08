#include "ReadThread.h"
#include "qfile.h"

ReadThread::ReadThread(QString f, QTextBrowser* d)
{
	filepath = f;
	display = d;
	data = nullptr;
	ready = false;
}

// 使用Unicode范围来判断字符是否为汉字
bool isChineseCharacter(const QChar& character)
{
	return character >= 0x4e00 && character <= 0x9fff;
}

void ReadThread::run()
{	
	QFile file(filepath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
		//return nullptr;
	}
	Data*re = new Data();

	QTextStream in(&file);
	QString kItem=""; //! 上一个选项卡名字
	QString notes = " "; // !上一个选项卡的批注
	//! 节点的属性信息
	//! <每行属性，每行属性值>
	QPair<QList<QList<QString>>, QList<QList<QString>>>* itemPair = new QPair<QList<QList<QString>>, QList<QList<QString>>>;
	

	QList<QList<QString>>*k = nullptr;
	QList<QList<QString>>*v = nullptr;

	
	//! 已丢弃
	//节点的属性信息
	QMap<QString, QString>* itemMapOut; 
	
	//! 已丢弃
	//节点属性的顺序
	QList<QString>* itemOrderOut;

	//! 每个节点的前缀起始
	int nodeStart = 1000;

	//! 按行读取文件
	bool isBreak = false;
	int rowCount = 0;
	while (!in.atEnd())
	{
		if (isBreak)
		{
			break;
		}
		QByteArray line = file.readLine(); rowCount++;
		QString str(line);
		str.remove("\n");

		//! 判断选项卡
		if (str.at(0) == '*')
		{
			if (str == "*NODE" || str == "*ELEMENT_SOLID" || str == "*KEYWORD" || str == "*PARAMETER_DUPLICATION" )//|| str == "*END"
				continue;
			if (kItem != "")
			{
// 				kItem = QString::number(nodeStart) + kItem; // 序号+节点 1000NT_SOLID
				kItem = kItem + "@"+ QString::number(nodeStart); // 节点+序号 NT_SOLID@1000
				itemPair->first = *k;
				itemPair->second = *v;
				re->rootList->append(itemPair);
				re->rootMap->insert(kItem, itemPair);
				re->rootOrder_notes->append(notes);
				nodeStart++;
			}
			if (str == "*END")
			{
				isBreak = true;
				continue;
			}
			display->append(QString::number(rowCount) + "  " +str);

			itemPair = new QPair<QList<QList<QString>>, QList<QList<QString>>>;
			k = new QList<QList<QString>>;
			v = new QList<QList<QString>>;

			//! 添加树节点顺序
// 			re->rootOrder->append(QString::number(nodeStart) + str.mid(1));
			re->rootOrder->append(str.mid(1)+"@"+ QString::number(nodeStart));
			
			str = str.simplified();
			kItem = str.mid(1);		
			qDebug() << kItem;
			notes = " ";

			itemMapOut = new QMap<QString, QString>();
			itemOrderOut = new QList<QString>();
		}//if
		//! 添加选项卡属性值
		else if (str.at(0) == '$')
		{
			if (isChineseCharacter(str.at(1)))// 是批注
			{
				notes = notes + str.mid(1) + u8"。";
				display->append(QString::number(rowCount) + "  " + str);
			}
			else if (str.at(1) == " ")
			{
				QList<QString>kk;
				QList<QString>vv;
				display->append(QString::number(rowCount) + "  " + str);
				// tesing
	// 			if (rowCount == 48)
	// 			{
	// 				int i = 1;
	// 			}
	// 			if (rowCount == 62)
	// 			{
	// 				int i = 1;
	// 			}
				//end testing
				str = str.simplified(); // ----------------------
				QStringList key = str.split(" "); // 下标1开始，最后一个为unused要丢弃

				int len = key.length();
				line = file.readLine(); rowCount++;// 属性的值 下标0开始

				QString strvalue(line);
				strvalue.remove("\n");
				display->append(QString::number(rowCount) + "  " + strvalue);
				strvalue = strvalue.simplified(); // ----------------------


				QStringList value = strvalue.split(" "); // 下标0开始

				for (int i = 0; i < len - 1; i++)
				{
					QT_TRY
					{
						itemOrderOut->append(key[i + 1]);
// 					qDebug() << key[i + 1];
						if (key[i + 1].mid(0, 6) == "unused")
						{
							kk.append(key[i + 1]);
							vv.append(" ");

							itemMapOut->insert(key[i + 1], " ");
						}
						else
						{
							if (i >= value.size())
							{
								kk.append(key[i + 1]);
								vv.append(" ");


								itemMapOut->insert(key[i + 1], " ");
							}
							else
							{
								kk.append(key[i + 1]);
								vv.append(value[i]);

								itemMapOut->insert(key[i + 1], value[i]);
							}

						}

					}
						QT_CATCH(const char* ex)
					{
						// 捕获并处理异常
						qDebug() << "Exception caught:" << ex;
					}
				}// for


				k->append(kk);
				v->append(vv);

				re->rootMapOut->insert(kItem, itemMapOut);
				re->orderOut->insert(kItem, itemOrderOut);

			}//else if 	
		}
	}//end while

	// 测试数据
// 	auto tk = re->rootOrder;
// 	auto kv1 = re->rootMap->value((*tk)[2]);
	
	ready = true;
	this->data = re;

	file.close();
}