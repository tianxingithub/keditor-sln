#include "TreeWidget.h"
#include <QStandardItemModel>
#include <QTreeWidgetItem>

TreeWidget::TreeWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::TreeWidgetClass())
{
	ui->setupUi(this);

	QSplitter* splitter = new QSplitter(Qt::Vertical);

	treeItem = new QTreeWidget(splitter);
	itemAttr = new QTableWidget(splitter);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(splitter);

	this->setLayout(layout);

	// 创建根节点
	root = new QTreeWidgetItem(treeItem);
	root->setText(0, u8"激活能量数值");
	root->setIcon(0, QIcon("E:/Logo/fir.png"));


	

	treeItem->expandAll();  // 展开所有节点
	treeItem->show();
}

TreeWidget::~TreeWidget()
{
	delete ui;

}
