#pragma once

#include <QWidget>
#include "ui_DisplayWidget.h"
#include "QTextBrowser"

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayWidgetClass; };
QT_END_NAMESPACE

//! 文本显示的类
class DisplayWidget : public QWidget
{
	Q_OBJECT

public:
	DisplayWidget(QWidget *parent = nullptr);
	~DisplayWidget();

private:
	Ui::DisplayWidgetClass *ui;
public:
	//! 显示文件控件
	QTextBrowser* textDisplay;
	//! 垂直布局
	//QVBoxLayout* layout;
};
