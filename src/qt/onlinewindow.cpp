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

#include "onlinewindow.h"
#include "ui_onlinewindow.h"
#include "addressbookpage.h"


OnlineWindow::OnlineWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::OnlineWindowClass)
{
    ui->setupUi(this);
    addressBookPage = new AddressBookPage(AddressBookPage::ForEditing, AddressBookPage::SendingTab);
   //setFixedSize(500,400);
}

void OnlineWindow::createActions()
{
	connect(addressBookAction, SIGNAL(triggered()), this, SLOT(showNormalIfMinimized()));
    connect(addressBookAction, SIGNAL(triggered()), this, SLOT(gotoAddressBookPage()));	
	
	QActionGroup *tabGroup = new QActionGroup(this);
	addressBookAction = new QAction(QIcon(":/icons/address-book2"), tr("&Address Book"), this);
    addressBookAction->setToolTip(tr("Edit the list of stored addresses and labels"));
    addressBookAction->setCheckable(true);
    tabGroup->addAction(addressBookAction);
}

void OnlineWindow::gotoAddressBookPage()
{
    addressBookAction->setChecked(true);
    centralWidget->setCurrentWidget(addressBookPage);

    exportAction->setEnabled(true);
    disconnect(exportAction, SIGNAL(triggered()), 0, 0);
    connect(exportAction, SIGNAL(triggered()), addressBookPage, SLOT(exportClicked()));
}

void OnlineWindow::tabJoined()
{
	joining=true;
}
void OnlineWindow::tabJoining()
{
	joining=false;
       
}

void OnlineWindow::closeEvent(QCloseEvent *event)
{
	(void) event;

	QMapIterator<QString, Serveur*> i(serveurs);

	while(i.hasNext())
	{
		i.next();
		QMapIterator<QString, QTextEdit*> i2(i.value()->conversations);
		while(i2.hasNext())
		{
			i2.next();
            i.value()->sendData("QUIT "+i2.key() + " ");
		}
	}
}
void OnlineWindow ::setModel(ClientModel *model)
{
    this->model = model;
}


OnlineWindow::~OnlineWindow()
{
    delete ui;
    QMapIterator<QString, Serveur*> i(serveurs);

    while(i.hasNext())
    {
        i.next();
        QMapIterator<QString, QTextEdit*> i2(i.value()->conversations);
        while(i2.hasNext())
        {
            i2.next();
            i.value()->sendData("QUIT "+i2.key() + " ");
        }
    }
}
