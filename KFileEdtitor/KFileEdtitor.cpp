#include "KFileEdtitor.h"
#include "qfiledialog.h"
#include <QHeaderView>
#include "qlabel.h"
#include "QLineEdit"
#include "ReadThread.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "Data.h"

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

    translator = nullptr;
    translator = new Translator(":/ts/kTranslation.json");

    fileRW = new ReadWrite();
    connect(fileRW, &ReadWrite::finishedSig, this, &KFileEdtitor::readOverSlot);
    data = nullptr;
    itemDialog = nullptr;

    addPlot();


    
}

KFileEdtitor::~KFileEdtitor()
{
    delete ui;
}

void KFileEdtitor::addPlot()
{
    connect(ui->actionOpen, &QAction::triggered, this, &KFileEdtitor::getData);
    connect(ui->actionSave, &QAction::triggered, this, &KFileEdtitor::exportData);
    connect(treeWidget->treeItem, &QTreeWidget::doubleClicked, this, &KFileEdtitor::treeViewDoubleClick);
    connect(treeWidget->treeItem, &QTreeWidget::clicked, this, &KFileEdtitor::treeViewClick);

    connect(ui->menuDemo, &QAction::triggered, this, &KFileEdtitor::funDemo);
    //connect(ui->menuDemo, &QAction::triggered, new Translator(), &Translator::testSlots); // ��ȷ
    //connect(ui->menuDemo, &QAction::triggered, new ReadWrite(), &ReadWrite::testSlots);


}

void KFileEdtitor::funDemo()
{
    QMap<QString, QMap<QString, QString>>m;
    m.insert(QString("a"), QMap<QString, QString>());
    auto mm = m["b"];


}

void KFileEdtitor::getData()
{
    QString filepath = QFileDialog::getOpenFileName(// ��������
        this, u8"��K�ļ�",
        ".",
        "k files (*.k);;All files (*.*)");
    if (filepath == nullptr)
        return;
    //QString filepath = "C:/Users/HanShan/Downloads/Demo_86.k";
    //QString filepath = "C:/Users/HanShan/Downloads/Demo_86_1219.k";
    //QString filepath = "C:/Users/HanShan/Downloads/3layer_shot_root.k";
    
    /*this->data = */fileRW->readData(filepath, displayWidget->textDisplay);
    displayItem();
}

void KFileEdtitor::exportData()
{
	auto obj = dynamic_cast<ReadThread*>(sender());
	if (obj)
	{
		this->data = obj->data;
	}
    if (data == nullptr)
        return;
    QString filepath = QFileDialog::getSaveFileName(this, u8"����K�ļ�",
        ".",
        "k files (*.k);;all files(*.*)");
    fileRW->writeDataRoot(filepath,data);

}

void KFileEdtitor::displayItem()
{


    if (data == nullptr)
        return;
    treeWidget->treeItem->setRootIsDecorated(false);
    for each (auto s in *(data->rootOrder))
    {
        auto a = data->rootMap->value(s);
        if (a==nullptr)
            continue;
        QTreeWidgetItem* childItem1 = new QTreeWidgetItem(treeWidget->root);
        childItem1->setIcon(0, QIcon(":/images/sec.png"));
        childItem1->setText(0, s);
    }
    treeWidget->treeItem->expandAll();  // չ�����нڵ�
}

void KFileEdtitor::readOverSlot(Data*re)
{
    int a = 1;
	
    this->data = re;
    displayItem();
}

void KFileEdtitor::treeViewDoubleClick()
{
    //showMapDialog();
    showPairDialog();
    //freshData();
}

void KFileEdtitor::showPairDialog()
{
	if (this->data == nullptr)
		return;
	QTreeWidgetItem* item = treeWidget->treeItem->currentItem();
	QString key = item->text(0);
	if (key == u8"����������ֵ")return;

	itemDialog = new ItemDialog(this);
	itemDialog->setWindowTitle(key);
    connect(itemDialog, &ItemDialog::doubleClickSig, this, &KFileEdtitor::treeViewClick);

    auto kvPair = data->rootMap->value(key);

    auto kRow = kvPair->first;
    auto vRow = kvPair->second;

    if (kRow.size() == 0)
    {
        qDebug() << "���ݳ���k.size()=0,������ֵ";
        return;
    }
    int w = 90, h = 30, px = 10, py = 40;
    int numCount = 0;
    int rowCount = 0;
    for (auto row : kRow)//������һ�е�����
    {
        for (int i=0;i<row.size();i++)
        {
            auto k = row[i];
            int kcount = kRow.last().size() <= 8 ? 8 : kRow.last().size();

            QLabel* label = new QLabel(itemDialog);
			//! ��������
			if (translator->json != nullptr)
			{
				QString jLable = translator->json->value(k).toString();
				if (jLable != "")
				{
					label->setText(jLable);
				}
				else
				{
					label->setText(k);
				}
			}
			else
			{
				label->setText(k);
			}

            // ���Lable��unusedֱ�ӷ��������
			if (k.mid(0, 6) == "unused")
			{
				label->setGeometry((w + px) * (kcount-1) + 45, (h + py) * rowCount, w, h);
			}
			else
			{
				label->setGeometry((w + px) * i + 45, (h + py) * rowCount, w, h);
			}

			
			//! ��unused���Ե�ֵ����Ϊ�����޸ĵ�textBrowser
            if (k.mid(0, 6) == "unused")
            {
				QLineEdit* value = new QLineEdit(itemDialog);
				value->setText(vRow[rowCount][i]);
                value->setAlignment(Qt::AlignCenter);
                value->setGeometry((w + px) * (kcount-1) + 45, (h + py) * rowCount + 35, w, h);
            }
            else
            {
				QLineEdit* value = new QLineEdit(itemDialog);
				value->setText(vRow[rowCount][i]);
                value->setGeometry((w + px) * i + 45, (h + py) * rowCount + 35, w, h);
            }

        }
        rowCount++;
    }

    int xcount = kRow.last().size() <= 8 ? 8 : kRow.last().size();
    
    int xx = (w + px) * (xcount+1), yy = (h + py) * (kRow.size() + 1) + 50;
    itemDialog->resize(xx, yy);
	itemDialog->save->move(xx - 240, yy - 50);
	itemDialog->save->setVisible(true);
	itemDialog->cacel->move(xx - 140, yy - 50);
	itemDialog->cacel->setVisible(true);
    itemDialog->show();
}

void KFileEdtitor::showMapDialog()
{
    if (this->data == nullptr)
        return;
    QTreeWidgetItem* item = treeWidget->treeItem->currentItem();
    QString key = item->text(0);
    if (key == u8"����������ֵ")return;

    itemDialog = new ItemDialog(this);
    itemDialog->setWindowTitle(key);

    int numCount = 0;
    int w = 90, h = 30, px = 10, py = 40;

    QMap<QString, QString>* kv = nullptr;
    QList<QString>* attOrder = nullptr;

    kv = data->rootMapOut->value(key);
    attOrder = data->orderOut->value(key);

    if (kv == nullptr || attOrder == nullptr)
        return;

    for each (auto k in *attOrder)
    {
        QLabel* label = new QLabel(itemDialog);
        //! ��������
        if (translator != nullptr)
        {
            QString jLable = translator->json->value(k).toString();
            if (jLable != "")
            {
                label->setText(jLable);
            }
            else
            {
                label->setText(k);
            }
        }
        else
        {
            label->setText(k);
        }

        //! ���Lable��unusedֱ�ӷ��������
        if (k.mid(0, 6) == "unused")
        {
            label->setGeometry((w + px) * (7 % 8) + 45, (h + py) * (numCount / 8), w, h);
            numCount = numCount + (7 - (numCount % 8));
        }
        else
        {
            label->setGeometry((w + px) * (numCount % 8) + 45, (h + py) * (numCount / 8), w, h);
        }

        //! ��unused���Ե�ֵ����Ϊ�����޸ĵ�textBrowser
        if (k.mid(0, 6) == "unused")
        {
            QTextBrowser* value = new QTextBrowser(itemDialog);
            value->setText(kv->value(k));
            value->setAlignment(Qt::AlignCenter);
            numCount = numCount - (7 - (numCount % 8));
            value->setGeometry((w + px) * (7 % 8) + 45, (h + py) * (numCount / 8) + 35, w, h);
            numCount = numCount + (7 - (numCount % 8));
        }
        else
        {
            QLineEdit* value = new QLineEdit(itemDialog);
            value->setText(kv->value(k));
            value->setGeometry((w + px) * (numCount % 8) + 45, (h + py) * (numCount / 8) + 35, w, h);
        }
        numCount++;
    }

    int xx = (w + px) * 9, yy = (h + py) * (numCount / 8 + 1) + 50;
    itemDialog->resize(xx, yy);

    itemDialog->save->move(xx - 240, yy - 50);
    itemDialog->save->setVisible(true);
    itemDialog->cacel->move(xx - 140, yy - 50);
    itemDialog->cacel->setVisible(true);

    itemDialog->show();    
}

void KFileEdtitor::freshData()
{
    if (itemDialog == nullptr)
    {
        return;
    }
    //! �Ի������������
    auto diaData = itemDialog->dialogMapData;
    auto krows = itemDialog->krows;
    auto vrows = itemDialog->vrows;
    if (krows == nullptr)
    {
        return;
    }
    //! �Ի�����⣺Data�Ľڵ�
    QString k = itemDialog->windowTitle();
    //! �õ�ԭ���Ľڵ�
    auto oldPair = data->rootMap->value(k);
    auto oldKrows = oldPair->first;
    auto oldVrows = oldPair->second;
    QList<QList<QString>> newKrows;
    QList<QList<QString>> newVrows;
    int index = 0;
    for (auto r : oldKrows)
    {
        QList<QString>* rk = new QList<QString>;
        QList<QString>* rv = new QList<QString>;
        for (auto k : r) // kΪӢ��
        {
            //rk->append(krows->at(index));// ����������
            rk->append(k);// ����ǰ��Ӣ��
            rv->append(vrows->at(index));
            index++;
        }
        newKrows.append(*rk);
        newVrows.append(*rv);
        rk = new QList<QString>;
        rv = new QList<QString>;
    }
    auto a = newKrows.size(); // ����������
    auto b = oldKrows.size(); // ����ǰ��Ӣ��

    QPair< QList<QList<QString>>, QList<QList<QString>>>* newPair = new QPair< QList<QList<QString>>, QList<QList<QString>>>;
    newPair->first = newKrows;
    newPair->second = newVrows;
    data->rootMap->insert(k, newPair);
}



void KFileEdtitor::treeViewClick()
{
    
    if (this->data == nullptr)
        return;

    //! �õ���ǰ����ļ�
    QTreeWidgetItem* item = treeWidget->treeItem->currentItem();
    if (item->text(0) == u8"����������ֵ")
        return;
    freshData();

    /* ��������ģ�� */
    QStandardItemModel* model = new QStandardItemModel();
    /* ���ñ�������(��������ΪQStringList����) */
    model->setHorizontalHeaderLabels({ u8"����", u8"ֵ" });
    model->setItem(0, 0, new QStandardItem(u8"����"));
    model->setItem(0, 1, new QStandardItem(item->text(0)));

    /* ���ñ����ͼ���� */
    treeWidget->itemAttr->setModel(model);
    treeWidget->itemAttr->verticalHeader()->hide();//����ʾ���  
    
    auto a = item->text(0);
    auto b = data->rootMapOut;
    auto itemValue = data->rootMap->value(item->text(0));  // nullptr
    //auto valueOrder = data->rootOrder->value(item->text(0));

    auto itemPairOut = data->rootMap->value(a);
    int index = data->rootOrder->indexOf(a);
    auto itemPair = data->rootMap->value(a);
    auto itemK = itemPair->first;
    auto itemv = itemPair->second;

    QList<QString> showK;
    for (auto row : itemK) {
        for (auto i : row) {
            showK.append(i);
        }
    }
	QList<QString> showV;
	for (auto row : itemv) {
		for (auto i : row) {
			showV.append(i);
		}
	}
    

    if (itemValue == nullptr )//|| valueOrder == nullptr
        return;

    int lineCount = 1;
    for (int i = 0; i < showK.size(); i++)
    {
        if (showK[i].mid(0, 6) == "unused")
        {
            continue;
        }
        model->setItem(lineCount, 0, new QStandardItem(showK[i]));
        model->setItem(lineCount, 1, new QStandardItem(showV[i]));
        lineCount++;
    }

    /* ��ʾ */
    treeWidget->itemAttr->show();
}