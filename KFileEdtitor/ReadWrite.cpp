#include "ReadWrite.h"
#include "QFile"
#include "qtextstream.h"

ReadWrite::ReadWrite()
{
	
}

ReadWrite::~ReadWrite()
{

}

Data* ReadWrite::readData(QString filepath)
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

		//! 将内容显示到QText上面
		//! 显示所有内容还是可只显示选项卡内容

		str = str.simplified();
		//! 判断选项卡
		if (str.at(0) == '*') 
		{
			if (str == "*NODE" || str == "*ELEMENT_SOLID" || str == "*KEYWORD" || str == "*PARAMETER_DUPLICATION" || str == "*END")
				continue;
			kItem = str;
			itemMap = new QMap<QString, QString>();
			itemOrder = new QList<QString>();
		}
		//! 添加选项卡属性值
		else if (str.at(0) == '$' && str.at(1) != '#') 
		{
			QStringList key = str.split(" "); // 下标1开始，最后一个为unused要丢弃
			int len = key.length();
			if (key[len - 1].mid(0, 6) == "unused")
			{
				--len;
			}
			
			line = file.readLine(); // 属性的值 下标0开始
			QString strvalue(line);
			strvalue.remove("\n");
			strvalue = strvalue.simplified();
			QStringList value = strvalue.split(" "); // 下标0开始

			for (int i = 0; i < len - 1; i++)
			{
				QT_TRY{
					itemMap->insert(key[i + 1], value[i]);
					itemOrder->append(key[i + 1]);
				}
				QT_CATCH(...)
				{

				}
			}
			re->rootMap->insert(kItem, itemMap);
		}
	}

	file.close();

	return re;
}

void ReadWrite::writeData(QString filepath)
{

}