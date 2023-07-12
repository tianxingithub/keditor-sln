#include "KFileEdtitor.h"
#include "qfiledialog.h"
#include <QHeaderView>
#include "qlabel.h"
#include "QTextEdit"

KFileEdtitor::KFileEdtitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KFileEdtitorClass())
{
    ui->setupUi(this);

    treeWidget = new TreeWidget(ui->centralWidget);
    treeWidget->setMinimumSize(250, 600);
    ui->verticalLayout->addWidget(treeWidget);

    displayWidget = new DisplayWidget(ui->centralWidget);
    displayWidget->setMinimumSize(600, 500);
	ui->horizontalLayout->addWidget(displayWidget);

    //jsonTranslator = new Translator("E:/PERACD/.sln/k/kTranslation.json");

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
    connect(ui->menuDemo, &QAction::triggered, this, &KFileEdtitor::funDemo);
}

void KFileEdtitor::funDemo()
{
    itemDialog = new ItemDialog(this);
    itemDialog->show();
}

void KFileEdtitor::getData()
{
    QString filepath = QFileDialog::getOpenFileName(// 正常加载
        this, "open k file",
        ".",
        "k files (*.k);;All files (*.*)");
    if (filepath == nullptr)
        return;
    
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
    if (this->data == nullptr)
        return;
    QTreeWidgetItem* item = treeWidget->treeItem->currentItem();
    QString key = item->text(0);
    if (key == u8"激活能量数值")return;

    itemDialog = new ItemDialog(this);
    itemDialog->setWindowTitle(key);

    int labelCount = 0;
    int w = 90, h = 30, px = 10, py = 40;

    QMap<QString, QString>* kv = nullptr;
    QList<QString>* attOrder = nullptr;

    kv = data->rootMap->value('*' + key);
    attOrder = data->order->value('*' + key);

    if (kv == nullptr || attOrder == nullptr)
        return;

    for each (auto k in *attOrder)
    {
        QLabel* label = new QLabel(itemDialog);
        label->setText(k);
        if (k.mid(0, 6) == "unused")
        {
            label->setGeometry((w + px) * (7 % 8) + 45, (h + py) * (labelCount / 8), w, h);
        }
        else
        {
            label->setGeometry((w + px) * (labelCount % 8) + 45, (h + py) * (labelCount / 8), w, h);
        }
        
        
        if (k.mid(0, 6) == "unused") 
        {
            QTextBrowser* value = new QTextBrowser(itemDialog);
			value->setText(kv->value(k));
            value->setAlignment(Qt::AlignCenter);
			value->setGeometry((w + px) * (7 % 8) + 45, (h + py) * (labelCount / 8) + 35, w, h);
        }
        else
        {
			QTextEdit* value = new QTextEdit(itemDialog);
			value->setText(kv->value(k));
			value->setGeometry((w + px) * (labelCount % 8) + 45, (h + py) * (labelCount / 8) + 35, w, h);
        }
        labelCount++;
    }

    int xx = (w + px) * 9, yy = (h + py) * (labelCount / 8 + 1) + 50;
    itemDialog->resize(xx, yy);

    itemDialog->save->move(xx - 240, yy - 50);
    itemDialog->save->setVisible(true);
    itemDialog->cacel->move(xx - 140, yy - 50);
    itemDialog->cacel->setVisible(true);


    itemDialog->show();
    //displayWidget->textDisplay->append("treeViewDoubleClick");
}

void KFileEdtitor::treeViewClick()
{
    if (this->data == nullptr)
        return;

    //treeWidget->itemAttr->clearContents(); // 清除所有单元格的内容
    //! 得到当前点击的键
    QTreeWidgetItem* item = treeWidget->treeItem->currentItem();

    /* 创建数据模型 */
    QStandardItemModel* model = new QStandardItemModel();
    /* 设置表格标题行(输入数据为QStringList类型) */
    model->setHorizontalHeaderLabels({ u8"属性", u8"值" });
    model->setItem(0, 0, new QStandardItem(u8"名字"));
    model->setItem(0, 1, new QStandardItem(item->text(0)));

    /* 设置表格视图数据 */
    treeWidget->itemAttr->setModel(model);
    treeWidget->itemAttr->verticalHeader()->hide();//不显示序号  
    

    //! 加载键的属性值并显示
    QMap<QString, QString >* itemValue = nullptr;
    QList<QString >* valueOrder = nullptr;

    itemValue = data->rootMap->value('*'+item->text(0));  // nullptr
    valueOrder = data->order->value('*' + item->text(0));

    if (itemValue == nullptr || valueOrder == nullptr)
        return;

    int lineCount = 0;
    for each (auto k in *valueOrder)
    {
        if (k.mid(0, 6) == "unused") 
        {
            continue;
        }
        model->setItem(lineCount, 0, new QStandardItem(k));
        model->setItem(lineCount, 1, new QStandardItem(itemValue->value(k)));
        lineCount++;
    }

    /* 显示 */
    treeWidget->itemAttr->show();
}