#pragma once

#include <QWidget>
#include "ui_ItemWidget.h"
#include "qpushbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ItemWidgetClass; };
QT_END_NAMESPACE

class ItemWidget : public QWidget
{
	Q_OBJECT

public:
	ItemWidget(QWidget *parent = nullptr);
	~ItemWidget();

public:
	QPushButton* save;
	QPushButton* cacel;

public:
	void saveItem();


private:
	Ui::ItemWidgetClass *ui;
};
