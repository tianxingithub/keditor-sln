#include "ReadWrite.h"
#include "QFile"
#include "qtextstream.h"
#include "qtextbrowser.h"
#include "QDebug"

ReadWrite::ReadWrite()
{
	
}

ReadWrite::~ReadWrite()
{

}

Data* ReadWrite::readData(QString filepath, QTextBrowser* display)
{

	Data* re = new Data();
	QFile file(filepath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return nullptr;

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
		//display->append(str);
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
					if(key[i + 1].mid(0,6)=="unused")
						itemMap->insert(key[i + 1], "");
					else
						itemMap->insert(key[i + 1], value[i]);														
				}
				QT_CATCH(...)
				{

				}
			}
			re->rootMap->insert(kItem, itemMap);
			re->order->insert(kItem, itemOrder);
		}
	}

	file.close();

	return re;
}

void ReadWrite::writeData(QString filepath, Data* data)
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
				auto les = 8 - (kindex % 8) + 1;
				txtOutput << n2.rightJustified(les * 10, ' '); //arg("", (les +1)*10, QLatin1Char(' '));
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
			}
		}
	}
		
		




	f.close();
}