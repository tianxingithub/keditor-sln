#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KFileEdtitor.h"
#include "TreeWidget.h"
#include "DisplayWidget.h"
#include "ReadWrite.h"
#include "ItemDialog.h"
#include "QJsonObject"
#include "Translator.h"

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

    //! 双击树子节点弹出属性值
    void treeViewDoubleClick();
    //! 在TableWidget里面显示属性
    void treeViewClick();
    
    
    // 【测试用】
    void funDemo();

private:
    Ui::KFileEdtitorClass *ui;


public:
	//! 翻译json对象
    Translator* translator;
	//! 获取对话框数据并更新
	void freshData();
    //! 弹出数据
    void showDialog();
    //! 导出数据
    void exportData();
	//! 显示文件的树节点信息
	void displayItem();

private:
    //! 文件节点树
    TreeWidget* treeWidget;
    //! 文本内容
    DisplayWidget* displayWidget;
    //! 弹出的对话框
    ItemDialog* itemDialog;
    //! 读写文件
    ReadWrite* fileRW;
    //! 读取的数据
    Data* data;
};
