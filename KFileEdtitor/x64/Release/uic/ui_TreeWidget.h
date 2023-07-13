/********************************************************************************
** Form generated from reading UI file 'TreeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEWIDGET_H
#define UI_TREEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeWidgetClass
{
public:

    void setupUi(QWidget *TreeWidgetClass)
    {
        if (TreeWidgetClass->objectName().isEmpty())
            TreeWidgetClass->setObjectName(QString::fromUtf8("TreeWidgetClass"));
        TreeWidgetClass->resize(183, 413);

        retranslateUi(TreeWidgetClass);

        QMetaObject::connectSlotsByName(TreeWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *TreeWidgetClass)
    {
        TreeWidgetClass->setWindowTitle(QApplication::translate("TreeWidgetClass", "TreeWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeWidgetClass: public Ui_TreeWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEWIDGET_H
