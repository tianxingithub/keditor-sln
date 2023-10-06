#include "ItemDialog.h"
#include "qlayout.h"
#include "QLabel"
#include "QLineEdit"
#include "QDebug"

ItemDialog::ItemDialog(QWidget*parent)
	: QDialog(parent)
	, ui(new Ui::ItemWidgetClass())
{
	save = new QPushButton(u8"����", this);
	cacel = new QPushButton(u8"ȡ��", this);
	save->setVisible(false);
	cacel->setVisible(false);
	
	dialogMapData = nullptr;
	krows = nullptr;
	vrows = nullptr;
	//onlyValue = nullptr;

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
	//! ����Ի��������QMap��ֵ��Ϣ
	QMap<QString, QString >* kv = new QMap<QString, QString>;
	//! ��������Label�ؼ���TextEdit�ؼ�
	QList<QLabel*> labelList = this->findChildren<QLabel*>(); // ��˳��
	QList<QLineEdit*> lineEditList = this->findChildren<QLineEdit*>(); // ��˳��
	onlyValue = this->findChildren<QLineEdit*>();
	//! �Ѽ�ֵ��Ϣд�뵽QMap��
	krows = new QList<QString>;
	vrows = new QList<QString>;
// 	int kCount = labelList.size();

	for (int i = 0; i < lineEditList.size(); i++)
	{
		auto k = labelList.at(i*2)->text();
		auto v = lineEditList.at(i)->text();
		krows->append(k);
		vrows->append(v);
	}	
	emit doubleClickSig();
	//! �رյ�ǰ����
	this->close();
	
}

