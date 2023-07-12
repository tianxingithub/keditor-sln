#pragma once

#include <QWidget>
#include "ui_ItemWidget.h"
#include "qpushbutton.h"
#include "QDialog"
#include "KFileEdtitor.h"

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

public:
	//! 得到对话框里面控件的信息
	QMap<QString, QString >* getDialogData();


private:
	Ui::ItemWidgetClass *ui;
};
