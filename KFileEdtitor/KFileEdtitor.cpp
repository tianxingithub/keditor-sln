#include "KFileEdtitor.h"

KFileEdtitor::KFileEdtitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KFileEdtitorClass())
{
    ui->setupUi(this);
    treeWidget = new TreeWidget(ui->centralWidget);
    treeWidget->setMinimumSize(200, 400);
    ui->verticalLayout->addWidget(treeWidget);
   // ui->widget->layout()->addWidget(treeWidget);

    displayWidget = new DisplayWidget(ui->centralWidget);
    displayWidget->setMinimumSize(400, 400);
	ui->horizontalLayout->addWidget(displayWidget);
	// ui->widget->layout()->addWidget(treeWidget);
}

KFileEdtitor::~KFileEdtitor()
{
    delete ui;
}
