#include "ReadThread.h"
#include "qfile.h"

ReadThread::ReadThread(QString f, QTextBrowser* d)
{
	filepath = f;
	display = d;
	data = nullptr;
	ready = false;
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
	QString kItem; //! 上一个选项卡名字
	QMap<QString, QString>* itemMap; //! 节点的属性信息
	QList<QString>* itemOrder; //! 节点属性的顺序

	//! 按行读取文件
	while (!in.atEnd())
	{
		QByteArray line = file.readLine();
		QString str(line);
		str.remove("\n");
		//display->append(str); // 与42互斥
		//! 将内容显示到QText上面
		//! 显示所有内容还是可只显示选项卡内容

		//! 判断选项卡
		if (str.at(0) == '*')
		{
			if (str == "*NODE" || str == "*ELEMENT_SOLID" || str == "*KEYWORD" || str == "*PARAMETER_DUPLICATION" || str == "*END")
				continue;
			display->append(str);
			//! 添加树节点顺序
			re->rootOrder->append(str.mid(1));
			str = str.simplified();
			kItem = str.mid(1);
			itemMap = new QMap<QString, QString>();
			itemOrder = new QList<QString>();
		}
		//! 添加选项卡属性值
		else if (str.at(0) == '$' && str.at(1) != '#')
		{
			display->append(str);
			str = str.simplified();
			QStringList key = str.split(" "); // 下标1开始，最后一个为unused要丢弃

			int len = key.length();
			/*if (key[len - 1].mid(0, 6) == "unused")
			{
				--len;
			}*/

			line = file.readLine(); // 属性的值 下标0开始

			QString strvalue(line);
			strvalue.remove("\n");
			display->append(strvalue);
			strvalue = strvalue.simplified();

			QStringList value = strvalue.split(" "); // 下标0开始

			for (int i = 0; i < len - 1; i++)
			{
				QT_TRY
				{
					itemOrder->append(key[i + 1]);
					if (key[i + 1].mid(0, 6) == "unused")
					{
						itemMap->insert(key[i + 1], "");
						// 抛出异常
						throw "Exception occurred";
					}						
					else
					{
						itemMap->insert(key[i + 1], value[i]);
					}						
				}
				QT_CATCH(const char* ex)
				{
					// 捕获并处理异常
					qDebug() << "Exception caught:" << ex;
				}
			}
			re->rootMap->insert(kItem, itemMap);
			re->order->insert(kItem, itemOrder);
		}
		
	}

	ready = true;
	this->data = re;

	file.close();
}