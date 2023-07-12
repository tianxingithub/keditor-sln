#include "Translator.h"
#include "QTextCodec"

Translator::Translator(QString path = "")
{
	filepath = path;
	json = readJson();

}

QJsonObject* Translator::readJson()
{
	QFile file(filepath);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Failed to open JSON file.";
		return nullptr;
	}

	// 读取JSON文件内容
	QByteArray jsonData = file.readAll();

	// 指定文件编码
	QTextCodec* codec = QTextCodec::codecForName("GBK");
	QString jsonString = codec->toUnicode(jsonData);

	// 解析JSON数据
	QJsonParseError parseError;
	QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &parseError);
	//QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &parseError);

	if (parseError.error != QJsonParseError::NoError) {
		qDebug() << "Failed to parse JSON:" << parseError.errorString();
		return nullptr;
	}


	// 检查解析是否成功
	if (jsonDoc.isNull())
	{
		qDebug() << "Failed to parse JSON data.";
		return nullptr;
	}

	// 将JSON数据转换为对象
	json = new QJsonObject(jsonDoc.object());

	// 读取对象中的数据
	//QString name = jsonObject["name"].toString();
	//int age = jsonObject["age"].toInt();
	//QString name = (*json)["slsfac"].toString();
	//QString name2 = (*json)["rwnpal"].toString();
	
	// 打印读取的数据
	//qDebug() << "Name:" << name;
	//qDebug() << "Age:" << age;
	//qDebug() << name << name2;
}