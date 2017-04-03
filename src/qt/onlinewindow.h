/*Copyright (C) 2009 Cleriot Simon
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA*/

#ifndef ONLINEWINDOW_H
#define ONLINEWINDOW_H

#include <QtGui>
#include <QtNetwork>
#include "clientmodel.h"
#include "onlinewindowutil.h"

class AddressBookPage;

namespace Ui
{
    class OnlineWindowClass;
}

class OnlineWindow : public QWidget
{
    Q_OBJECT

public:
    OnlineWindow(QWidget *parent = 0);
    ~OnlineWindow();
    void setModel(ClientModel *model);
    Serveur * currentTab();
	signals:
		void changeTab();

	public slots:
		void tabJoined();
		void tabJoining();

private:
	Ui::OnlineWindowClass *ui;
    ClientModel *model;
    QMap<QString,Serveur *> serveurs;
	bool joining;
	void closeEvent(QCloseEvent *event);
	AddressBookPage *addressBookPage;
	QAction *addressBookAction;
	QStackedWidget *centralWidget;
	    QAction *exportAction;
		    void createActions();

	
private slots:
		  void gotoAddressBookPage();

};

#endif // CHATWINDOW_H
