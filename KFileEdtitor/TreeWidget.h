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


class TreeWidget : public QWidget
{
	Q_OBJECT

public:
	TreeWidget(QWidget *parent = nullptr);
	~TreeWidget();

private:
	Ui::TreeWidgetClass *ui;
public:
	//! 树节点View
	QTreeWidget* treeItem;

	//! 树节点属性tableView
	QTableWidget* itemAttr;

	//! 根节点
	QTreeWidgetItem* root;

private:
	void initTree();
	void initTable();
};
