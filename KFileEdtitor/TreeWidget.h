#pragma once

#include <QWidget>
#include "ui_TreeWidget.h"
#include "QTreeWidget"
#include "QTreeWidget"
#include "QTableWidget"
#include "QPushButton"
#include "QVBoxLayout"
#include "QSplitter"
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class TreeWidgetClass; };
QT_END_NAMESPACE

class CustomTreeView : public QTreeWidget
{

};

//! �ļ��ڵ�ͽڵ�����
class TreeWidget : public QWidget
{
	Q_OBJECT

public:
	TreeWidget(QWidget *parent = nullptr);
	~TreeWidget();

private:
	Ui::TreeWidgetClass *ui;
public:
	//! ���ڵ�View
	QTreeWidget* treeItem;

	//! ���ڵ�����tableView
	QTableView* itemAttr;

	//! ���ڵ�
	QTreeWidgetItem* root;

public:
	void initTree();
	void initTable();
};
