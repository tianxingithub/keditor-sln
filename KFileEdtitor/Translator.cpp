#include "Translator.h"
#include <QJsonDocument>
#include <QJsonObject>
#include "QFile"
#include "QIODevice"
#include "QDebug"

//Translator::Translator(QString path="")
//{
//	//filepath = path;
//	//json = readJson();
//}

//QJsonObject* Translator::readJson()
//{
//	QFile file(filepath);
//
//	if (!file.open(QIODevice::ReadOnly))
//	{
//		qDebug() << "Failed to open JSON file.";
//		return nullptr;
//	}
//
//	// 读取JSON文件内容
//	QByteArray jsonData = file.readAll();
//
//	// 解析JSON数据
//	QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
//
//	// 检查解析是否成功
//	if (jsonDoc.isNull())
//	{
//		qDebug() << "Failed to parse JSON data.";
//		return nullptr;
//	}
//
//	// 将JSON数据转换为对象
//	json = &(jsonDoc.object());
//
//	// 读取对象中的数据
//	//QString name = jsonObject["name"].toString();
//	//int age = jsonObject["age"].toInt();
//
//	// 打印读取的数据
//	//qDebug() << "Name:" << name;
//	//qDebug() << "Age:" << age;
//}