#pragma once
#include "Data.h"
class ReadWrite
{
public:
	ReadWrite();
	~ReadWrite();

	//! 解析K文件
	Data* readData(QString filepath);

	//! 写入修改后的K文件节点信息
	void writeData(QString filepath);
};

