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
	itemAttr = new QTableWidget(splitter);

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
	itemAttr->setColumnCount(2);// 设置列数
	QStringList headerLabels;
	headerLabels << u8"属性" << u8"值";
	itemAttr->setHorizontalHeaderLabels(headerLabels);
	//itemAttr->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	//itemAttr->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
