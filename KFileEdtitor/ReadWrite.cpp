#include "ReadWrite.h"
#include "QFile"

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
		return;



	return re;
}

void ReadWrite::writeData(QString filepath)
{

}