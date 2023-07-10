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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayWidgetClass
{
public:
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *DisplayWidgetClass)
    {
        if (DisplayWidgetClass->objectName().isEmpty())
            DisplayWidgetClass->setObjectName(QString::fromUtf8("DisplayWidgetClass"));
        DisplayWidgetClass->resize(309, 413);
        verticalLayout_2 = new QVBoxLayout(DisplayWidgetClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

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
