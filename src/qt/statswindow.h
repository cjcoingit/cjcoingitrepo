#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include <QWidget>

namespace Ui {
	class Statswindow;
}
class WalletModel;

class Statswindow : public QWidget
{
    Q_OBJECT

public:
    explicit Statswindow(QWidget *parent = 0);
    void setModel(WalletModel *model);


virtual ~Statswindow();    

private slots:
    void on_Coinmarketcap_clicked();
	void on_Bitinfocharts_clicked();

private:
	Ui::Statswindow *ui;
    WalletModel *model;
};

#endif // STATSWINDOW_H