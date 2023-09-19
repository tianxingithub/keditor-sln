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

//! ��������
class KFileEdtitor : public QMainWindow
{
    Q_OBJECT

public:
    KFileEdtitor(QWidget *parent = nullptr);
    ~KFileEdtitor();
    void addPlot();

private:
    //! �õ������������
    void getData();

    //! ˫�����ӽڵ㵯������ֵ
    void treeViewDoubleClick();
    //! ��TableWidget������ʾ����
    void treeViewClick();
    
    
    // �������á�
    void funDemo();

private:
    Ui::KFileEdtitorClass *ui;


public:
	//! ����json����
    Translator* translator;
    //! itemDialog����
//     ItemDialog* itemdialog;

public:
	//! ��ȡ�Ի������ݲ�����
	void freshData();
    //! ��������
    void showMapDialog();
    void showPairDialog();
    //! ��������
    void exportData();
	//! ��ʾ�ļ������ڵ���Ϣ
	void displayItem();

private:
    //! �ļ��ڵ���
    TreeWidget* treeWidget;
    //! �ı�����
    DisplayWidget* displayWidget;
    //! �����ĶԻ���
    ItemDialog* itemDialog;
    //! ��д�ļ�
    ReadWrite* fileRW;
    //! ��ȡ������
    Data* data;
};
