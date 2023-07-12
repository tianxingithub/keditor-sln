#pragma once

#include <QWidget>
#include "ui_ItemWidget.h"
#include "qpushbutton.h"
#include "QDialog"

QT_BEGIN_NAMESPACE
namespace Ui { class ItemWidgetClass; };
QT_END_NAMESPACE

//! 双击节点弹出的对话框
class ItemDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ItemDialog(QWidget*parent = nullptr);
	~ItemDialog();

public:
	QPushButton* save;
	QPushButton* cacel;
	//! 对话框里面控件的QMap
	QMap<QString, QString >* dialogData;
public:
	//! 得到对话框里面控件的信息
	void getDialogData();


private:
	Ui::ItemWidgetClass *ui;
};
