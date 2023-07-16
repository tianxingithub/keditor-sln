#pragma once
#include <QString>
#include "QMap"

//! 树节点的键值和其属性值
class Data
{
public:
	Data();
	~Data();
public:
	//! 已丢弃
	QMap<QString , QMap<QString , QString >*>* rootMapOut;

	//! 树节点的键值
	QMap<QString, QPair<QList<QString >, QList<QString >>*>* rootMap;

	//! 树节点的顺序
	QList<QString>* rootOrder;

	//! 树节点属性的顺序
	QMap<QString , QList<QString >*>* order;

	//! 打开的文件名称
	QString filename;

public:
	//<QString, QMap<QString, QString >*>* getRootMap
};

