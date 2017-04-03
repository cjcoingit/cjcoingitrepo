#ifndef TWITTERFEED_H
#define TWITTERFEED_H

#include <QWidget>

namespace Ui {
	class Twitterfeed;
}
class WalletModel;

class Twitterfeed : public QWidget
{
    Q_OBJECT

public:
    explicit Twitterfeed(QWidget *parent = 0);
    void setModel(WalletModel *model);


virtual ~Twitterfeed();    

private slots:
    void on_Reload_clicked();

    void on_Back_clicked();

private:
	Ui::Twitterfeed *ui;
    WalletModel *model;
};

#endif // TWITTERFEED_H