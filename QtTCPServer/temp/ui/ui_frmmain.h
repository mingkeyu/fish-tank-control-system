/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "frmtcpclient.h"
#include "frmtcpserver.h"
#include "frmudpserver.h"

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    frmTcpClient *tabTcpClient;
    frmTcpServer *tabTcpServer;
    frmUdpServer *tabUdpServer;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QString::fromUtf8("frmMain"));
        frmMain->resize(800, 600);
        verticalLayout = new QVBoxLayout(frmMain);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(frmMain);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::South);
        tabTcpClient = new frmTcpClient();
        tabTcpClient->setObjectName(QString::fromUtf8("tabTcpClient"));
        tabWidget->addTab(tabTcpClient, QString());
        tabTcpServer = new frmTcpServer();
        tabTcpServer->setObjectName(QString::fromUtf8("tabTcpServer"));
        tabWidget->addTab(tabTcpServer, QString());
        tabUdpServer = new frmUdpServer();
        tabUdpServer->setObjectName(QString::fromUtf8("tabUdpServer"));
        tabWidget->addTab(tabUdpServer, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(frmMain);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTcpClient), QApplication::translate("frmMain", "TCP\345\256\242\346\210\267\347\253\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTcpServer), QApplication::translate("frmMain", "TCP\346\234\215\345\212\241\345\231\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabUdpServer), QApplication::translate("frmMain", "UDP\346\234\215\345\212\241\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
