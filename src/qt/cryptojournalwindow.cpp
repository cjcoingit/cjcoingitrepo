#include "ui_cryptojournalwindow.h"
#include "guiutil.h"
#include "bitcoingui.h"
#include "util.h"
#include "main.h"
#include <QtCore>
#include <QtGui>
#include <QtWebKit>

Cryptojournalwindow::Cryptojournalwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cryptojournalwindow),
    model(0)
{
    ui->setupUi(this);
}
    void Cryptojournalwindow::setModel(WalletModel *model)
{
    this->model = model;
    if(!model)
        return;
}

Cryptojournalwindow::~Cryptojournalwindow()
{
    delete ui;
}

void Cryptojournalwindow::on_Reload_clicked()
{
    ui->webView->reload();
}

void Cryptojournalwindow::on_CryptoJournal_clicked()
{
    ui->webView->load(QUrl("https://cryptojournal.news/"));
}
void Cryptojournalwindow::on_Yobit_clicked()
{
    ui->webView->load(QUrl("http://coindesk.com/"));
}