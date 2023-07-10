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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KFileEdtitorClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionImport;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KFileEdtitorClass)
    {
        if (KFileEdtitorClass->objectName().isEmpty())
            KFileEdtitorClass->setObjectName(QString::fromUtf8("KFileEdtitorClass"));
        KFileEdtitorClass->resize(306, 485);
        actionOpen = new QAction(KFileEdtitorClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(KFileEdtitorClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionImport = new QAction(KFileEdtitorClass);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        centralWidget = new QWidget(KFileEdtitorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(widget_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        KFileEdtitorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KFileEdtitorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 306, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        KFileEdtitorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KFileEdtitorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        KFileEdtitorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KFileEdtitorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        KFileEdtitorClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addAction(actionImport);

        retranslateUi(KFileEdtitorClass);

        QMetaObject::connectSlotsByName(KFileEdtitorClass);
    } // setupUi

    void retranslateUi(QMainWindow *KFileEdtitorClass)
    {
        KFileEdtitorClass->setWindowTitle(QApplication::translate("KFileEdtitorClass", "KFileEdtitor", nullptr));
        actionOpen->setText(QApplication::translate("KFileEdtitorClass", "Open", nullptr));
        actionSave->setText(QApplication::translate("KFileEdtitorClass", "Save", nullptr));
        actionImport->setText(QApplication::translate("KFileEdtitorClass", "Import", nullptr));
        menu->setTitle(QApplication::translate("KFileEdtitorClass", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KFileEdtitorClass: public Ui_KFileEdtitorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KFILEEDTITOR_H
