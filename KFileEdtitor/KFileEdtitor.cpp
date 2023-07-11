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

    displayWidget = new DisplayWidget(ui->centralWidget);
    displayWidget->setMinimumSize(400, 400);
	ui->horizontalLayout->addWidget(displayWidget);

    fileRW = new ReadWrite();
    data = nullptr;

    addPlot();
}

KFileEdtitor::~KFileEdtitor()
{
    delete ui;
}

void KFileEdtitor::addPlot()
{
    connect(ui->actionOpen, &QAction::triggered, this, &KFileEdtitor::getData);
    connect(treeWidget->treeItem, &QTreeWidget::doubleClicked, this, &KFileEdtitor::treeViewDoubleClick);
    connect(treeWidget->treeItem, &QTreeWidget::clicked, this, &KFileEdtitor::treeViewClick);
}

void KFileEdtitor::getData()
{
    QString filepath = QFileDialog::getOpenFileName(// 正常加载
        this, "open k file",
        ".",
        "k files (*.k);;All files (*.*)");
    
    this->data = fileRW->readData(filepath, displayWidget->textDisplay);
    
    //displayWidget->textDisplay->append(filepath);
    displayItem();
}

void KFileEdtitor::displayItem()
{
    treeWidget->treeItem->setRootIsDecorated(false);
    for each (auto s in *(data->rootOrder))
    {
        QTreeWidgetItem* childItem1 = new QTreeWidgetItem(treeWidget->root);
        childItem1->setIcon(0, QIcon("E:/Logo/sec.png"));
        childItem1->setText(0, s.mid(1));
    }
    treeWidget->treeItem->expandAll();  // 展开所有节点
}

void KFileEdtitor::treeViewDoubleClick()
{

    displayWidget->textDisplay->append("treeViewDoubleClick");
}

void KFileEdtitor::treeViewClick()
{
    if (this->data == nullptr)
        return;

    treeWidget->itemAttr->clearContents(); // 清除所有单元格的内容
    //! 得到当前点击的键
    QTreeWidgetItem* item = treeWidget->treeItem->currentItem();

    // 添加行数据



    //! 加载键的属性值并显示
    QMap<QString, QString >* itemValue = nullptr;
    QList<QString >* valueOrder = nullptr;

    itemValue = data->rootMap->value(item->text(0));  // 出错
    valueOrder = data->order->value(item->text(0));

    if (itemValue == nullptr || valueOrder == nullptr)
        return;

    for each (auto k in *valueOrder)
    {
        int rowCount = treeWidget->itemAttr->rowCount();// 当前行数
        treeWidget->itemAttr->setItem(rowCount, 0, new QTableWidgetItem(k));
    }


    delete itemValue;
    delete valueOrder;
}