/********************************************************************************
** Form generated from reading UI file 'ItemDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMDIALOG_H
#define UI_ITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemWidgetClass
{
public:

    void setupUi(QWidget *ItemWidgetClass)
    {
        if (ItemWidgetClass->objectName().isEmpty())
            ItemWidgetClass->setObjectName(QString::fromUtf8("ItemWidgetClass"));
        ItemWidgetClass->resize(600, 400);

        retranslateUi(ItemWidgetClass);

        QMetaObject::connectSlotsByName(ItemWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ItemWidgetClass)
    {
        ItemWidgetClass->setWindowTitle(QApplication::translate("ItemWidgetClass", "ItemWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ItemWidgetClass: public Ui_ItemWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMDIALOG_H
