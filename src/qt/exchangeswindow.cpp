#include "ui_exchangeswindow.h"
#include "guiutil.h"
#include "bitcoingui.h"
#include "util.h"
#include "main.h"
#include <QtCore>
#include <QtGui>
#include <QtWebKit>

Exchangeswindow::Exchangeswindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Exchangeswindow),
    model(0)
{
    ui->setupUi(this);
}
    void Exchangeswindow::setModel(WalletModel *model)
{
    this->model = model;
    if(!model)
        return;
}

Exchangeswindow::~Exchangeswindow()
{
    delete ui;
}

void Exchangeswindow::on_Yobit_clicked()
{
    ui->webView->load(QUrl("https://yobit.net/"));
}

void Exchangeswindow::on_Livecoin_clicked()
{
    ui->webView->load(QUrl("https://www.livecoin.net/en/trade/orderbook/"));
}
void Exchangeswindow::on_Cryptopia_clicked()
{
    ui->webView->load(QUrl("https://www.cryptopia.co.nz/Exchange/"));
}
void Exchangeswindow::on_Bittrex_clicked()
{
	ui->webView->load(QUrl("https://bittrex.com/home/markets/"));
}