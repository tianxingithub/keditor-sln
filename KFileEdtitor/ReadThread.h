#pragma once
#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "Data.h"
#include "qtextbrowser.h"
#include "KFileEdtitor.h"


class ReadThread : public QThread {
    Q_OBJECT
public:
    Data* data;
    QString filepath;
    QTextBrowser* display;
    bool ready;
    ReadThread(QString filepath, QTextBrowser* display);
public:
    void run() override;
};

