/********************************************************************************
** Form generated from reading UI file 'KFileEdtitor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KFILEEDTITOR_H
#define UI_KFILEEDTITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KFileEdtitorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KFileEdtitorClass)
    {
        if (KFileEdtitorClass->objectName().isEmpty())
            KFileEdtitorClass->setObjectName(QString::fromUtf8("KFileEdtitorClass"));
        KFileEdtitorClass->resize(600, 400);
        menuBar = new QMenuBar(KFileEdtitorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        KFileEdtitorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KFileEdtitorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        KFileEdtitorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(KFileEdtitorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        KFileEdtitorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(KFileEdtitorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        KFileEdtitorClass->setStatusBar(statusBar);

        retranslateUi(KFileEdtitorClass);

        QMetaObject::connectSlotsByName(KFileEdtitorClass);
    } // setupUi

    void retranslateUi(QMainWindow *KFileEdtitorClass)
    {
        KFileEdtitorClass->setWindowTitle(QApplication::translate("KFileEdtitorClass", "KFileEdtitor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KFileEdtitorClass: public Ui_KFileEdtitorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KFILEEDTITOR_H
