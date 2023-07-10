#include "TreeWidget.h"

TreeWidget::TreeWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::TreeWidgetClass())
{
	ui->setupUi(this);
}

TreeWidget::~TreeWidget()
{
	delete ui;
}
