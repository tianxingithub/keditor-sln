#include "KFileEdtitor.h"

KFileEdtitor::KFileEdtitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KFileEdtitorClass())
{
    ui->setupUi(this);
}

KFileEdtitor::~KFileEdtitor()
{
    delete ui;
}
