#pragma once

#include <QWidget>
#include "ui_TreeWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TreeWidgetClass; };
QT_END_NAMESPACE

class TreeWidget : public QWidget
{
	Q_OBJECT

public:
	TreeWidget(QWidget *parent = nullptr);
	~TreeWidget();

private:
	Ui::TreeWidgetClass *ui;
};
