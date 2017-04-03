#include "ui_statswindow.h"
#include "guiutil.h"
#include "bitcoingui.h"
#include "util.h"
#include "main.h"
#include <QtCore>
#include <QtGui>
#include <QtWebKit>

Statswindow::Statswindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statswindow),
    model(0)
{
    ui->setupUi(this);
}
    void Statswindow::setModel(WalletModel *model)
{
    this->model = model;
    if(!model)
        return;
}

Statswindow::~Statswindow()
{
    delete ui;
}

void Statswindow::on_Coinmarketcap_clicked()
{
    ui->webView->load(QUrl("http://coinmarketcap.com"));
}
void Statswindow::on_Bitinfocharts_clicked()
{
	ui->webView->load(QUrl("https://bitinfocharts.com/"));
}