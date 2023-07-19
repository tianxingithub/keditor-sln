#include "DisplayWidget.h"
#include "QSplitter"
#include "QVBoxLayout"
#include "QPushButton"

DisplayWidget::DisplayWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::DisplayWidgetClass())
{
	ui->setupUi(this);
	
	textDisplay = new QTextBrowser();

	this->layout()->setContentsMargins(0, 0, 0, 0);
	this->layout()->addWidget(textDisplay);
	
}

DisplayWidget::~DisplayWidget()
{
	delete ui;
}
