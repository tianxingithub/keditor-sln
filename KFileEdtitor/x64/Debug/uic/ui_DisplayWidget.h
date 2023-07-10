/********************************************************************************
** Form generated from reading UI file 'DisplayWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWIDGET_H
#define UI_DISPLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayWidgetClass
{
public:

    void setupUi(QWidget *DisplayWidgetClass)
    {
        if (DisplayWidgetClass->objectName().isEmpty())
            DisplayWidgetClass->setObjectName(QString::fromUtf8("DisplayWidgetClass"));
        DisplayWidgetClass->resize(600, 400);

        retranslateUi(DisplayWidgetClass);

        QMetaObject::connectSlotsByName(DisplayWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *DisplayWidgetClass)
    {
        DisplayWidgetClass->setWindowTitle(QApplication::translate("DisplayWidgetClass", "DisplayWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayWidgetClass: public Ui_DisplayWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWIDGET_H
