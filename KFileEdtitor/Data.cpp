#include "Data.h"

/*public:
	Data();
	~Data();
public:
	//! 树节点的键值
	QMap<QString , QMap<QString , QString >*>* rootMap;

	//! 树节点属性的顺序
	QMap<QString , QList<QString >*>* order;
*/
Data::Data()
{
	rootMap = new QMap<QString, QMap<QString, QString >*>();
	rootOrder = new QList<QString>;
	order = new QMap<QString, QList<QString >*>();
	filename = "";
}

Data::~Data()
{
	//delete rootMap;
	//delete order;
}