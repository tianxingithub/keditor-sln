#pragma once
#include "Data.h"
#include "qtextbrowser.h"


class ReadThread;
//! 读写解析文件类
class ReadWrite : public QObject
{
	Q_OBJECT
public:
	ReadWrite();
	~ReadWrite();

public slots:
	//! 解析K文件
	void readData(QString filepath,QTextBrowser* display);// 要复用可把display显示默认设置nullptr

	//! 只写入修改后K文件的节点信息
	void writeDataRoot(QString filepath, Data* data);

	//! 写入修改节点后的完整K文件
	void writeData(QString filepath, Data* data);

	//! 测试
	void testSlots();

public:
	void finishedSlot();
signals:
	void readFinishedSig(Data* re);
public:
	ReadThread* readthread;
};

