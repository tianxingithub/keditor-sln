#pragma once
#include <QString>
#include "QMap"

//! 树节点的键值和其属性值
class Data
{
public:
	//! 树节点的键值
	QMap<QString , QMap<QString , QString >*>* rootMap;

	//! 树节点属性的顺序
	QMap<QString , QList<QString >*>* order;

public:
	//<QString, QMap<QString, QString >*>* getRootMap
};

