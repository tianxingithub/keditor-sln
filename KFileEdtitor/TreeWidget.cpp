#include "TreeWidget.h"
#include <QStandardItemModel>
#include <QTreeWidgetItem>
#include <QHeaderView>

TreeWidget::TreeWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::TreeWidgetClass())
{
	ui->setupUi(this);

	QSplitter* splitter = new QSplitter(Qt::Vertical);

	treeItem = new QTreeWidget(splitter);
	itemAttr = new QTableView(splitter);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(splitter);
	this->setLayout(layout);

	initTree();
	initTable();
}

TreeWidget::~TreeWidget()
{
	delete ui;

}

void TreeWidget::initTable()
{

}

void TreeWidget::initTree()
{


	treeItem->setRootIsDecorated(false);
	treeItem->setColumnCount(1);
	treeItem->header()->setVisible(false);
	// 创建根节点
	root = new QTreeWidgetItem(treeItem);
	root->setText(0, u8"激活能量数值");
	root->setIcon(0, QIcon("E:/Logo/fir.png"));

	treeItem->expandAll();  // 展开所有节点
	treeItem->show();
}
