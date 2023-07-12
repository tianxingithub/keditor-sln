#pragma once
#include "Data.h"

//! 双击弹出数据后进行修改
class Viewer
{
public:
	//! 在树节点刷新修改后的属性值
	void freshItem();

	//! 把原来树节点的指针替换为修改后的指针
	void changePointer(QMap<QString, QString >* oldPointer, Data* data);



};

