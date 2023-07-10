#include "KFileEdtitor.h"

KFileEdtitor::KFileEdtitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KFileEdtitorClass())
{
    ui->setupUi(this);
    treeWidget = new TreeWidget(ui->centralWidget);
    displayWidget = new DisplayWidget(ui->centralWidget);

}

KFileEdtitor::~KFileEdtitor()
{
    delete ui;
}
