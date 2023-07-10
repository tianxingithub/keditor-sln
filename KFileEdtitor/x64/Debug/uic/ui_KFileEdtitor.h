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
#include <QtWidgets/QSplitter>
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
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *KFileEdtitorClass)
    {
        if (KFileEdtitorClass->objectName().isEmpty())
            KFileEdtitorClass->setObjectName(QString::fromUtf8("KFileEdtitorClass"));
        KFileEdtitorClass->resize(257, 325);
        actionOpen = new QAction(KFileEdtitorClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(KFileEdtitorClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionImport = new QAction(KFileEdtitorClass);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        centralWidget = new QWidget(KFileEdtitorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(verticalLayoutWidget);
        horizontalLayoutWidget = new QWidget(splitter);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(horizontalLayoutWidget);

        verticalLayout_2->addWidget(splitter);

        KFileEdtitorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KFileEdtitorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 257, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        KFileEdtitorClass->setMenuBar(menuBar);

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
