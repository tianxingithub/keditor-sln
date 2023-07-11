#pragma once

#include <QWidget>
#include "ui_DisplayWidget.h"
#include "QTextBrowser"

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayWidgetClass; };
QT_END_NAMESPACE

class DisplayWidget : public QWidget
{
	Q_OBJECT

public:
	DisplayWidget(QWidget *parent = nullptr);
	~DisplayWidget();

private:
	Ui::DisplayWidgetClass *ui;
public:
	QTextBrowser* textDisplay;
};
