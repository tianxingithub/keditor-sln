#include "TreeWidget.h"
#include <QStandardItemModel>

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
	

	// 创建 QStandardItemModel 作为树的数据模型
	QStandardItemModel* model = new QStandardItemModel();

	// 创建根节点
	root = new QStandardItem(u8"激发数值分析");
	
	root->setIcon(QIcon("E:/Logo/fir.png"));
	model->appendRow(root);//model->insertRow(0, rootItem);

	// 创建 QTreeView 并设置数据模型
	treeItem->setModel(model);
	treeItem->expandAll();  // 展开所有节点

	treeItem->show();
}

TreeWidget::~TreeWidget()
{
	delete ui;

}
