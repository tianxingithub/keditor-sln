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
	QString kItem=""; //! ��һ��ѡ�����
	//! �ڵ��������Ϣ
	//! <ÿ�����ԣ�ÿ������ֵ>
	QPair<QList<QList<QString>>, QList<QList<QString>>>* itemPair = new QPair<QList<QList<QString>>, QList<QList<QString>>>;
	

	QList<QList<QString>>*k = nullptr;
	QList<QList<QString>>*v = nullptr;

	//! �Ѷ���
	//�ڵ��������Ϣ
	QMap<QString, QString>* itemMapOut; 
	
	//! �Ѷ���
	//�ڵ����Ե�˳��
	QList<QString>* itemOrderOut;

	//! ÿ���ڵ��ǰ׺��ʼ
	int nodeStart = 1000;

	//! ���ж�ȡ�ļ�
	bool isBreak = false;
	while (!in.atEnd())
	{
		if (isBreak)
		{
			break;
		}
		QByteArray line = file.readLine();
		QString str(line);
		str.remove("\n");

		//! �ж�ѡ�
		if (str.at(0) == '*')
		{
			if (str == "*NODE" || str == "*ELEMENT_SOLID" || str == "*KEYWORD" || str == "*PARAMETER_DUPLICATION" )//|| str == "*END"
				continue;
			if (kItem != "")
			{
				kItem = QString::number(nodeStart) + kItem; // ���+�ڵ� 1000NT_SOLID
				itemPair->first = *k;
				itemPair->second = *v;
				re->rootList->append(itemPair);
				re->rootMap->insert(kItem, itemPair);
				nodeStart++;
			}
			if (str == "*END")
			{
				isBreak = true;
				continue;
			}
			display->append(str);

			itemPair = new QPair<QList<QList<QString>>, QList<QList<QString>>>;
			k = new QList<QList<QString>>;
			v = new QList<QList<QString>>;

			//! ������ڵ�˳��
			re->rootOrder->append(QString::number(nodeStart) + str.mid(1));
			str = str.simplified();
			kItem = str.mid(1);			

			itemMapOut = new QMap<QString, QString>();
			itemOrderOut = new QList<QString>();
		}//if
		//! ���ѡ�����ֵ
		else if (str.at(0) == '$' && str.at(1) == " ")
		{
			QList<QString>kk;
			QList<QString>vv;
			display->append(str);
			str = str.simplified();
			QStringList key = str.split(" "); // �±�1��ʼ�����һ��ΪunusedҪ����

			int len = key.length();
			line = file.readLine(); // ���Ե�ֵ �±�0��ʼ

			QString strvalue(line);
			strvalue.remove("\n");
			display->append(strvalue);
			strvalue = strvalue.simplified();

			QStringList value = strvalue.split(" "); // �±�0��ʼ

			for (int i = 0; i < len - 1; i++)
			{
				QT_TRY
				{
					itemOrderOut->append(key[i + 1]);
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
					// ���񲢴����쳣
					qDebug() << "Exception caught:" << ex;
				}
			}// for


			k->append(kk);
			v->append(vv);

			re->rootMapOut->insert(kItem, itemMapOut);
			re->orderOut->insert(kItem, itemOrderOut);		
			
		}//else if 	
		
	}

	// ��������
	auto tk = re->rootOrder;
	auto kv1 = re->rootMap->value((*tk)[2]);
	
	ready = true;
	this->data = re;

	file.close();
}