#ifndef NEWSWINDOW_H
#define NEWSWINDOW_H

#include <QWidget>

namespace Ui {
	class Newswindow;
}
class WalletModel;

class Newswindow : public QWidget
{
    Q_OBJECT

public:
    explicit Newswindow(QWidget *parent = 0);
    void setModel(WalletModel *model);


virtual ~Newswindow();    

private slots:
    void on_Coindesk_clicked();

    void on_Cointelegraph_clicked();

	void on_Cryptocoinsnews_clicked();
	
	void on_Bitcointalk_clicked();
private:
	Ui::Newswindow *ui;
    WalletModel *model;
};

#endif // NEWSWINDOW_H