#include "DisplayWidget.h"

DisplayWidget::DisplayWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::DisplayWidgetClass())
{
	ui->setupUi(this);
}

DisplayWidget::~DisplayWidget()
{
	delete ui;
}
