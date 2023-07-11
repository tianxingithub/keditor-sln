#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KFileEdtitor.h"
#include "TreeWidget.h"
#include "DisplayWidget.h"
#include "ReadWrite.h"
#include "ItemWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class KFileEdtitorClass; };
QT_END_NAMESPACE

class KFileEdtitor : public QMainWindow
{
    Q_OBJECT

public:
    KFileEdtitor(QWidget *parent = nullptr);
    ~KFileEdtitor();
    void addPlot();

private:
    void getData();
    void displayItem();
    void treeViewDoubleClick();
    void treeViewClick();
    void funDemo();

private:
    Ui::KFileEdtitorClass *ui;


public:

private:
    TreeWidget* treeWidget;
    DisplayWidget* displayWidget;
    ItemWidget* itemWidget;
    ReadWrite* fileRW;
    Data* data;
};
