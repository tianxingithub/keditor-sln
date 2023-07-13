#pragma once
#include "Data.h"
#include "qtextbrowser.h"


//! 读写解析文件类
class ReadWrite
{
	//Q_OBJECT
public:
	ReadWrite();
	~ReadWrite();

public slots:
	//! 解析K文件
	Data* readData(QString filepath,QTextBrowser* display);// 要复用可把display显示默认设置nullptr

	//! 写入修改后的K文件节点信息
	void writeData(QString filepath, Data* data);

	//! 测试
	void fileTest() {
		int i = 1;

	}
};

