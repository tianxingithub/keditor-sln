#include "TreeWidget.h"

TreeWidget::TreeWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::TreeWidgetClass())
{
	ui->setupUi(this);

	QSplitter* splitter = new QSplitter(Qt::Vertical);

	treeItem = new QTreeView(splitter);
	itemAttr = new QTableView(splitter);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(splitter);

	this->setLayout(layout);
	
}

TreeWidget::~TreeWidget()
{
	delete ui;

}
