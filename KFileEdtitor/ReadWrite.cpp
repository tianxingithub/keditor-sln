#include "ReadWrite.h"
#include "QFile"
#include "qtextstream.h"
#include "qtextbrowser.h"
#include "QDebug"
#include "ReadThread.h"
#include "KFileEdtitor.h"

ReadWrite::ReadWrite()
{
	
}

ReadWrite::~ReadWrite()
{

}

Data* ReadWrite::readData(QString filepath, QTextBrowser* display)
{
	ReadThread* readthread = new ReadThread(filepath, display);
	readthread->run();
	//readthread->start();
	connect(readthread, &QThread::finished, new KFileEdtitor(), &KFileEdtitor::displayItem);


	//Data* re = nullptr;
	Data* re = readthread->data;
	return re;
}

void ReadWrite::writeDataRoot(QString filepath, Data* data)
{
	QFile f(filepath);
	if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		qDebug() << u8"打开文件失败";
		return;
	}
	QTextStream txtOutput(&f);

	//! 树节点顺序
	auto node1 = data->rootOrder;
	
	//! 开始遍历树节点
	for (auto n1 : *node1)
	{
		txtOutput << "*"+n1.mid(4) << endl;

		////! 得到树节点map的顺序
		//auto node2 = data->orderOut->value(n1);
		////! 得到树节点的map
		//auto node2Map = data->rootMapOut->value(n1);
		//if(node2==nullptr|| node2Map==nullptr)
		//	continue;
		
		//! 节点的QPair
		auto kvpair = data->rootMap->value(n1);
		auto krows = kvpair->first;
		auto vrows = kvpair->second;
		if (krows.size() == 0)
		{
			qDebug() << "krows.size() = 0";
			return;
		}
			
		int rcount = 0;
		for (auto row : krows)
		{
			int kcount = row.size();
			int space = kcount <= 8 ? 10 : 80 / kcount;
			int count = 0;
			for (auto k : row)
			{
				if (count == 0)
				{
					txtOutput << "$"<< k.rightJustified(space - 1, ' ');
					count++;
				}
				else
				{
					if (k.mid(0, 6) == "unused")
					{
						txtOutput << k.rightJustified((8-count)*10, ' ');
						//count++;
					}
					else
					{
						txtOutput << k.rightJustified(space, ' ');
						count++;
					}						
				}
			}
			txtOutput << endl;
			count = 0;
			for (int i = 0; i < row.size(); i++)
			{
				if (krows[rcount][i] == "unused")
				{
					txtOutput <<  vrows[rcount][i].rightJustified((8 - count) * 10, ' ');
				}
				else
				{
					txtOutput << vrows[rcount][i].rightJustified(space, ' ');
					count++;
				}					
			}
			txtOutput << endl;
			rcount++;
		}

		////! 格式化输出节点属性
		//int kindex = 1; // 准备写入第几个属性
		//QList<QString>write; // 每一排已经写入的数据

		//int space = 10; // 一个属性占多少位
		//int endcount = 8; // 满多少个换行
		//if (node2->last().mid(0,6) != "unused")
		//{
		//	if ((node2->size()) % endcount != 0)
		//	{
		//		space = 80 / (node2->size());
		//		endcount = node2->size();
		//		qDebug() << n1<<node2->size();
		//	}
		//}


		//for (auto n2 : *node2) // 遍历属性的键
		//{					
		//	if (kindex% endcount == 1) // 属性的第一个前面有$
		//	{
		//		txtOutput << "$"<<n2.rightJustified(space-1, ' '); //arg("",9, QLatin1Char(' ')); ///rightJustified(9, ' ');
		//		write.append(n2);
		//		kindex++;
		//	}
		//	else if(n2.mid(0,6)=="unused") // 一排属性没有8个用unused填充
		//	{
		//		auto les = (endcount - (kindex % endcount) + 1);
		//		txtOutput << n2.rightJustified(les % endcount * space, ' '); //arg("", (les +1)*10, QLatin1Char(' '));
		//		kindex = endcount+1;
		//	}
		//	else
		//	{
		//		txtOutput <<  n2.rightJustified(space,  ' '); //arg("", (kindex%8)*10, QLatin1Char(' '));
		//		write.append(n2);
		//		kindex++;
		//	}
		//	if (kindex % (endcount+1) == 0)
		//	{	
		//		txtOutput << endl;
		//		int vindex = 1;
		//		for (auto w : write)
		//		{
		//			if (w.mid(0, 6) == "unused")
		//			{
		//				auto les = endcount - (vindex % endcount) + 1;
		//				txtOutput << QString("⁣⁣⁣⁣　").rightJustified(les * space, ' '); //arg("", (les + 1) * 10, QLatin1Char(' '));
		//				vindex++;
		//			}
		//			else
		//			{
		//				txtOutput << node2Map->value(w).rightJustified(space, ' '); //arg("", (vindex%8)*10, QLatin1Char(' '));
		//				vindex++;
		//			}
		//		}
		//		txtOutput << endl;
		//		write.clear();
		//		kindex = 1;
		//	}
		//}
	}
	f.close();
}

void ReadWrite::writeData(QString filepath, Data* data)
{
	QFile ofile(filepath);
	if (!ofile.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		qDebug() << u8"创建文件失败";
		return;
	}
	QFile ifile(filepath);
	if (!ifile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << u8"导出时读取原始文件失败";
		return;
		//return nullptr;
	}

	QTextStream in(&ifile);
	while (!in.atEnd()) //! 按行读取文件
	{
		QByteArray line = ifile.readLine();
		QString str(line);
		if (str.at(0) == '*')
		{
			if (str == "*NODE" || str == "*ELEMENT_SOLID" || str == "*KEYWORD" || str == "*PARAMETER_DUPLICATION" || str == "*END")
			{
				// 把读取的写进输出文件

			}
			
		}
	}









	ofile.close();
	ifile.close();
}

void ReadWrite::testSlots()
{
	auto obj = dynamic_cast<ReadThread*>(sender());
	if (obj)
	{
		auto re = obj->data;
	}
	
	
	qDebug() << "*****************ReadWrite::testSlots*************";
}