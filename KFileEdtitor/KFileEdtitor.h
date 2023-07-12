#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KFileEdtitor.h"
#include "TreeWidget.h"
#include "DisplayWidget.h"
#include "ReadWrite.h"
#include "ItemDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class KFileEdtitorClass; };
QT_END_NAMESPACE

//! 主界面类
class KFileEdtitor : public QMainWindow
{
    Q_OBJECT

public:
    KFileEdtitor(QWidget *parent = nullptr);
    ~KFileEdtitor();
    void addPlot();

private:
    //! 得到解析后的数据
    void getData();
    //! 显示文件的树节点信息
    void displayItem();
    //! 双击树子节点弹出属性值
    void treeViewDoubleClick();
    //! 在TableWidget里面显示属性
    void treeViewClick();
    // 【测试用】
    void funDemo();

private:
    Ui::KFileEdtitorClass *ui;


public:

private:
    TreeWidget* treeWidget;
    DisplayWidget* displayWidget;
    ItemDialog* itemDialog;
    ReadWrite* fileRW;
    Data* data;
};
