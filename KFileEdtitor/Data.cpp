#include "Data.h"

Data::Data()
{
	rootMap = new QMap<QString, QPair<QList<QList<QString>>, QList<QList<QString>>>*>;
	rootMapOut = new QMap<QString, QMap<QString, QString >*>();
	rootOrder = new QList<QString>;
	rootOrder_notes = new QList<QString>;
	orderOut = new QMap<QString, QList<QString >*>();
	rootList = new QList<QPair<QList<QList<QString>>, QList<QList<QString>>>*>;
	filename = "";
}

Data::~Data()
{
	//delete rootMap;
	//delete order;
}