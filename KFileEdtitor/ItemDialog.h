#pragma once

#include <QWidget>
#include "ui_ItemWidget.h"
#include "qpushbutton.h"
#include "QDialog"
#include "QLineEdit"
#include "QPair"

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
	QMap<QString, QString >* dialogMapData;

	//! 对话框里面控件的k
	QList<QString>* krows;
	//! 对话框里面控件的v
	QList<QString>* vrows;

	//! 修改框里面的值
	QList<QLineEdit*> onlyValue;

public:
	//! 得到对话框里面控件的信息
	void getDialogData();

signals:
	//! 数据保存后发送消息
	void doubleClickSig();
private:
	Ui::ItemWidgetClass *ui;
};
