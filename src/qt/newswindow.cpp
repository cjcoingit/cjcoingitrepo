#include "ui_newswindow.h"
#include "guiutil.h"
#include "bitcoingui.h"
#include "util.h"
#include "main.h"
#include <QtCore>
#include <QtGui>
#include <QtWebKit>

Newswindow::Newswindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Newswindow),
    model(0)
{
    ui->setupUi(this);
}
    void Newswindow::setModel(WalletModel *model)
{
    this->model = model;
    if(!model)
        return;
}

Newswindow::~Newswindow()
{
    delete ui;
}

void Newswindow::on_Coindesk_clicked()
{
    ui->webView->load(QUrl("http://coindesk.com/"));
}

void Newswindow::on_Cointelegraph_clicked()
{
    ui->webView->load(QUrl("https://cointelegraph.com/"));
}

void Newswindow::on_Cryptocoinsnews_clicked()
{
    ui->webView->load(QUrl("http://cryptocoinsnews.com/"));
}

void Newswindow::on_Bitcointalk_clicked()
{
	ui->webView->load(QUrl("https://bitcointalk.org/"));
}