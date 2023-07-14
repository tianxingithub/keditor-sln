#include "ReadWrite.h"
#include "QFile"
#include "qtextstream.h"
#include "qtextbrowser.h"
#include "QDebug"
#include "ReadThread.h"

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
	//connect(readthread, &QThread::finished, this, &ReadWrite::testSlots);


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
		txtOutput << "*"+n1 << endl;

		//! 得到树节点map的顺序
		auto node2 = data->order->value(n1);
		//! 得到树节点的map
		auto node2Map = data->rootMap->value(n1);
		
		//! 格式化输出节点属性
		int kindex = 1; // 准备写入第几个属性
		QList<QString>write; // 每一排已经写入的数据
		for (auto n2 : *node2) // 遍历属性的键
		{		
			
			if (kindex%8 == 1) // 属性的第一个前面有$
			{
				txtOutput << "$"<<n2.rightJustified(9, ' '); //arg("",9, QLatin1Char(' ')); ///rightJustified(9, ' ');
				write.append(n2);
				kindex++;
			}
			else if(n2.mid(0,6)=="unused") // 一排属性没有8个用unused填充
			{
				auto les = (8 - (kindex % 8) + 1);
				txtOutput << n2.rightJustified(les % 8 * 10, ' '); //arg("", (les +1)*10, QLatin1Char(' '));
				kindex = 9;				
			}
			else
			{
				txtOutput <<  n2.rightJustified(10,  ' '); //arg("", (kindex%8)*10, QLatin1Char(' '));
				write.append(n2);
				kindex++;
			}
			if (kindex % 9 == 0)
			{	
				txtOutput << endl;
				int vindex = 1;
				for (auto w : write)
				{
					if (w.mid(0, 6) == "unused")
					{
						auto les = 8 - (vindex % 8) + 1;
						txtOutput << QString("⁣⁣⁣⁣　").rightJustified(les * 10, ' '); //arg("", (les + 1) * 10, QLatin1Char(' '));
						vindex++;
					}
					else
					{
						txtOutput << node2Map->value(w).rightJustified(10, ' '); //arg("", (vindex%8)*10, QLatin1Char(' '));
						vindex++;
					}
				}
				txtOutput << endl;
				write.clear();
				kindex = 1;
			}
		}
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