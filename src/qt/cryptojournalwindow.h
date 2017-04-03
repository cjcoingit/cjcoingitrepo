#ifndef CRYPTOJOURNALWINDOW_H
#define CRYPTOJOURNALWINDOW_H

#include <QWidget>

namespace Ui {
	class Cryptojournalwindow;
}
class WalletModel;

class Cryptojournalwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Cryptojournalwindow(QWidget *parent = 0);
    void setModel(WalletModel *model);


virtual ~Cryptojournalwindow();    

private slots:
    void on_Reload_clicked();

    void on_Yobit_clicked();

	void on_CryptoJournal_clicked();
private:
	Ui::Cryptojournalwindow *ui;
    WalletModel *model;
};

#endif // CRYPTOJOURNALWINDOW_H