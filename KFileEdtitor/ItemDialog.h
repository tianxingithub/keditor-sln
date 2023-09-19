#pragma once

#include <QWidget>
#include "ui_ItemWidget.h"
#include "qpushbutton.h"
#include "QDialog"
#include "QLineEdit"
#include "QPair"

QT_BEGIN_NAMESPACE
namespace Ui { class ItemWidgetClass; };
QT_END_NAMESPACE

//! ˫���ڵ㵯���ĶԻ���
class ItemDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ItemDialog(QWidget*parent = nullptr);
	~ItemDialog();

public:
	QPushButton* save;
	QPushButton* cacel;

	//! �Ի�������ؼ���QMap
	QMap<QString, QString >* dialogMapData;

	//! �Ի�������ؼ���k
	QList<QString>* krows;
	//! �Ի�������ؼ���v
	QList<QString>* vrows;

	//! �޸Ŀ������ֵ
	QList<QLineEdit*> onlyValue;

public:
	//! �õ��Ի�������ؼ�����Ϣ
	void getDialogData();

signals:
	//! ���ݱ��������Ϣ
	void doubleClickSig();
private:
	Ui::ItemWidgetClass *ui;
};
