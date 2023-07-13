#pragma once
#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "Data.h"
#include "qtextbrowser.h"


class ReadThread : public QThread {
    Q_OBJECT
public:
    Data* data;
    QString filepath;
    QTextBrowser* display;
    ReadThread(QString filepath, QTextBrowser* display);
public:
    void run() override;
};

