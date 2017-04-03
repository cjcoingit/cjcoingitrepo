#include "ui_twitterfeed.h"
#include "guiutil.h"
#include "bitcoingui.h"
#include "util.h"
#include "main.h"
#include <QtCore>
#include <QtGui>
#include <QtWebKit>

Twitterfeed::Twitterfeed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Twitterfeed),
    model(0)
{
    ui->setupUi(this);
}
    void Twitterfeed::setModel(WalletModel *model)
{
    this->model = model;
    if(!model)
        return;
}

Twitterfeed::~Twitterfeed()
{
    delete ui;
}

void Twitterfeed::on_Reload_clicked()
{
    ui->webView->reload();
}

void Twitterfeed::on_Back_clicked()
{
    ui->webView->load(QUrl("https://cryptojournal.news/feed/"));
}