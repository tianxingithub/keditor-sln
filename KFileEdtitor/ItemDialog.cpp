#include "ItemDialog.h"
#include "qlayout.h"
#include "QLabel"
#include "QTextEdit"
#include "QDebug"

ItemDialog::ItemDialog(QWidget*parent)
	: QDialog(parent)
	, ui(new Ui::ItemWidgetClass())
{
	save = new QPushButton(u8"保存", this);
	cacel = new QPushButton(u8"取消", this);
	save->setVisible(false);
	cacel->setVisible(false);
	
	dialogData = nullptr;

	ui->setupUi(this);
	connect(this->save, &QPushButton::clicked, this, &ItemDialog::getDialogData);
	//connect(this->save, &QPushButton::clicked, new KFileEdtitor(), &KFileEdtitor::freshData);
	connect(this->cacel, &QPushButton::clicked, this, &QWidget::close);
}

ItemDialog::~ItemDialog()
{
	delete ui;
}

void ItemDialog::getDialogData()
{
	//! 储存对话框里面的键值信息
	QMap<QString, QString >* kv = new QMap<QString, QString>;
	//! 遍历所有Label控件和TextEdit控件
	QList<QLabel*> labelList = this->findChildren<QLabel*>();
	QList<QTextEdit*> textEditList = this->findChildren<QTextEdit*>();
	
	//! 把键值信息写入到QMap中
	for (int i = 0; i < labelList.size(); i++) 
	{
		kv->insert(labelList.at(i)->text(), textEditList.at(i)->toPlainText());
	}
	//! 把QMap传出去, 解析|判断是否合理
	//! 树节点的值
	QString title = this->windowTitle();
	//qDebug() << title;
	

	//! 关闭当前窗体
	this->close();

	dialogData = kv;
}

