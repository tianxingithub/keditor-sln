#pragma once
#include "QMap"
#include "QString"
#include <QJsonDocument>
#include <QJsonObject>
#include "QFile"
#include "QIODevice"
#include "QDebug"
//! 文本翻译
class Translator : public QObject
{
	//Q_OBJECT
public:
	//! 存储翻译数据
	QJsonObject* json;
	//! 翻译文件路径
	QString filepath;

public:
	Translator(QString filepath = "");

private:
	//! 读取翻译文件
	QJsonObject* readJson();

public slots: //slots可要可不要
	void testSlots();
	
};

