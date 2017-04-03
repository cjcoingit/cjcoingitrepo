#ifndef EXCHANGESWINDOW_H
#define EXCHANGESWINDOW_H

#include <QWidget>

namespace Ui {
	class Exchangeswindow;
}
class WalletModel;

class Exchangeswindow : public QWidget
{
    Q_OBJECT

public:
    explicit Exchangeswindow(QWidget *parent = 0);
    void setModel(WalletModel *model);


virtual ~Exchangeswindow();    

private slots:
    void on_Yobit_clicked();

    void on_Livecoin_clicked();
	
	void on_Cryptopia_clicked();
	
	void on_Bittrex_clicked();

private:
	Ui::Exchangeswindow *ui;
    WalletModel *model;
};

#endif // EXCHANGESWINDOW_H