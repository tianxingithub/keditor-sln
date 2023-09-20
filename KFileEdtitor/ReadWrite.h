#pragma once
#include "Data.h"
#include "qtextbrowser.h"


class ReadThread;
//! ��д�����ļ���
class ReadWrite : public QObject
{
	Q_OBJECT
public:
	ReadWrite();
	~ReadWrite();

public slots:
	//! ����K�ļ�
	void readData(QString filepath,QTextBrowser* display);// Ҫ���ÿɰ�display��ʾĬ������nullptr

	//! ֻд���޸ĺ�K�ļ��Ľڵ���Ϣ
	void writeDataRoot(QString filepath, Data* data);

	//! д���޸Ľڵ�������K�ļ�
	void writeData(QString filepath, Data* data);

	//! ����
	void testSlots();

public:
	void finishedSlot();
signals:
	void finishedSig(Data* re);
public:
	ReadThread* readthread;
};

