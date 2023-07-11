#include "ItemDialog.h"
#include "qlayout.h"

ItemDialog::ItemDialog(QWidget*parent)
	: QDialog(parent)
	, ui(new Ui::ItemWidgetClass())
{
	save = new QPushButton(u8"±£´æ", this);
	cacel = new QPushButton(u8"È¡Ïû", this);
	save->setVisible(false);
	cacel->setVisible(false);
	/*save->move(200, 200);
	cacel->move(300, 200);*/

	ui->setupUi(this);
	connect(this->save, &QPushButton::clicked, this, &ItemDialog::saveItem);
	connect(this->cacel, &QPushButton::clicked, this, &QWidget::close);
}

ItemDialog::~ItemDialog()
{
	delete ui;
}

void ItemDialog::saveItem()
{

}

