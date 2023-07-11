#include "KFileEdtitor.h"
#include "qfiledialog.h"

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

    fileRW = new ReadWrite();

    addPlot();
}

KFileEdtitor::~KFileEdtitor()
{
    delete ui;
}

void KFileEdtitor::addPlot()
{
    connect(ui->actionOpen, &QAction::triggered, this, &KFileEdtitor::getData);
    connect(treeWidget->treeItem, &QTreeView::doubleClicked, this, &KFileEdtitor::treeViewDoubleClick);
    connect(treeWidget->treeItem, &QTreeView::clicked, this, &KFileEdtitor::treeViewClick);
}

void KFileEdtitor::getData()
{
    QString filepath = QFileDialog::getOpenFileName(// 正常加载
        this, "open k file",
        ".",
        "k files (*.k);;All files (*.*)");
    
    this->data = fileRW->readData(filepath, displayWidget->textDisplay);
    
    //displayWidget->textDisplay->append(filepath);
    displayData();
}

void KFileEdtitor::displayData()
{
    treeWidget->treeItem->setRootIsDecorated(false);
    QMap<QString, QMap<QString, QString >*> ::const_iterator it;
    for (it = data->rootMap->constBegin(); it != data->rootMap->constEnd(); ++it) {
        QString key = it.key();
        // 创建子节点
        QStandardItem* childItem1 = new QStandardItem(key.mid(1));
        childItem1->setIcon(QIcon("E:/Logo/sec.png"));
        treeWidget->root->appendRow(childItem1);
    }
    treeWidget->treeItem->expandAll();  // 展开所有节点
}

void KFileEdtitor::treeViewDoubleClick()
{

    displayWidget->textDisplay->append("treeViewDoubleClick");
}

void KFileEdtitor::treeViewClick()
{
    displayWidget->textDisplay->append("treeViewClick");
}