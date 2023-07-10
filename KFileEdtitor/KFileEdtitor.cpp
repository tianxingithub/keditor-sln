#include "KFileEdtitor.h"

KFileEdtitor::KFileEdtitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KFileEdtitorClass())
{
    ui->setupUi(this);
    treeWidget = new TreeWidget(ui->centralWidget);
    ui->widget->layout()->addWidget(treeWidget);

    displayWidget = new DisplayWidget(ui->centralWidget);
    ui->widget_2->layout()->addWidget(displayWidget);
}

KFileEdtitor::~KFileEdtitor()
{
    delete ui;
}
