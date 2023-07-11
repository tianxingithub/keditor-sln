#include "ItemWidget.h"

ItemWidget::ItemWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ItemWidgetClass())
{

	ui->setupUi(this);
	connect(this->save, &QPushButton::clicked, this, &ItemWidget::saveItem);
	connect(this->cacel, &QPushButton::clicked, this, &QWidget::close);
}

ItemWidget::~ItemWidget()
{
	delete ui;
}

void ItemWidget::saveItem()
{

}

