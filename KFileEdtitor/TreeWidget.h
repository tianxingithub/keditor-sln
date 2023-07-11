#pragma once

#include <QWidget>
#include "ui_TreeWidget.h"
#include "QTreeView"
#include "QTableView"
#include "QPushButton"
#include "QVBoxLayout"
#include "QSplitter"
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class TreeWidgetClass; };
QT_END_NAMESPACE

class CustomTreeView : public QTreeView
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
	QTreeView* treeItem;

	//! 树节点属性tableView
	QTableView* itemAttr;

	//! 根节点
	QStandardItem* root;
};
