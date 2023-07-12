#include "Translator.h"
#include "QTextCodec"

Translator::Translator(QString path)
{
	filepath = path;
	json = nullptr;
	json = readJson();

	// 读取对象中的数据
	//QString name = (*json)["rwnpal"].toString();
	//qDebug() << name2;
	
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
	QJsonObject* re = new QJsonObject(jsonDoc.object());

	// 读取对象中的数据

	QString name2 = re->value("rwnpal").toString();
	qDebug() << name2;
	return re;
}

void Translator::TestJson()
{
	QString name2 = json->value("rwnpal").toString();
	qDebug() << name2;
}