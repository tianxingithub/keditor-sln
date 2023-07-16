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
	rootMap = new QMap<QString, QPair<QList<QList<QString>>, QList<QList<QString>>>*>;
	rootMapOut = new QMap<QString, QMap<QString, QString >*>();
	rootOrder = new QList<QString>;
	orderOut = new QMap<QString, QList<QString >*>();
	filename = "";
}

Data::~Data()
{
	//delete rootMap;
	//delete order;
}