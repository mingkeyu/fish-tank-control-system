/********************************************************************************
** Form generated from reading UI file 'frmtcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTCPCLIENT_H
#define UI_FRMTCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmTcpClient
{
public:
    QGridLayout *gridLayout;
    QTextEdit *txtMain;
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *ckHexReceive;
    QCheckBox *ckHexSend;
    QCheckBox *ckAscii;
    QCheckBox *ckShow;
    QCheckBox *ckDebug;
    QCheckBox *ckAutoSend;
    QComboBox *cboxInterval;
    QLabel *labServerIP;
    QLineEdit *txtServerIP;
    QLabel *labServerPort;
    QLineEdit *txtServerPort;
    QPushButton *btnConnect;
    QPushButton *btnSave;
    QPushButton *btnClear;
    QSpacerItem *spacer;
    QWidget *widget;
    QHBoxLayout *layTcpClient;
    QComboBox *cboxData;
    QPushButton *btnSend;

    void setupUi(QWidget *frmTcpClient)
    {
        if (frmTcpClient->objectName().isEmpty())
            frmTcpClient->setObjectName(QString::fromUtf8("frmTcpClient"));
        frmTcpClient->resize(800, 600);
        gridLayout = new QGridLayout(frmTcpClient);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        txtMain = new QTextEdit(frmTcpClient);
        txtMain->setObjectName(QString::fromUtf8("txtMain"));
        txtMain->setReadOnly(true);

        gridLayout->addWidget(txtMain, 0, 0, 1, 1);

        frame = new QFrame(frmTcpClient);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(170, 0));
        frame->setMaximumSize(QSize(170, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(9, 9, 9, 9);
        ckHexReceive = new QCheckBox(frame);
        ckHexReceive->setObjectName(QString::fromUtf8("ckHexReceive"));

        verticalLayout_5->addWidget(ckHexReceive);

        ckHexSend = new QCheckBox(frame);
        ckHexSend->setObjectName(QString::fromUtf8("ckHexSend"));

        verticalLayout_5->addWidget(ckHexSend);

        ckAscii = new QCheckBox(frame);
        ckAscii->setObjectName(QString::fromUtf8("ckAscii"));

        verticalLayout_5->addWidget(ckAscii);

        ckShow = new QCheckBox(frame);
        ckShow->setObjectName(QString::fromUtf8("ckShow"));

        verticalLayout_5->addWidget(ckShow);

        ckDebug = new QCheckBox(frame);
        ckDebug->setObjectName(QString::fromUtf8("ckDebug"));

        verticalLayout_5->addWidget(ckDebug);

        ckAutoSend = new QCheckBox(frame);
        ckAutoSend->setObjectName(QString::fromUtf8("ckAutoSend"));

        verticalLayout_5->addWidget(ckAutoSend);

        cboxInterval = new QComboBox(frame);
        cboxInterval->setObjectName(QString::fromUtf8("cboxInterval"));

        verticalLayout_5->addWidget(cboxInterval);

        labServerIP = new QLabel(frame);
        labServerIP->setObjectName(QString::fromUtf8("labServerIP"));

        verticalLayout_5->addWidget(labServerIP);

        txtServerIP = new QLineEdit(frame);
        txtServerIP->setObjectName(QString::fromUtf8("txtServerIP"));

        verticalLayout_5->addWidget(txtServerIP);

        labServerPort = new QLabel(frame);
        labServerPort->setObjectName(QString::fromUtf8("labServerPort"));

        verticalLayout_5->addWidget(labServerPort);

        txtServerPort = new QLineEdit(frame);
        txtServerPort->setObjectName(QString::fromUtf8("txtServerPort"));

        verticalLayout_5->addWidget(txtServerPort);

        btnConnect = new QPushButton(frame);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        verticalLayout_5->addWidget(btnConnect);

        btnSave = new QPushButton(frame);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        verticalLayout_5->addWidget(btnSave);

        btnClear = new QPushButton(frame);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        verticalLayout_5->addWidget(btnClear);

        spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(spacer);


        gridLayout->addWidget(frame, 0, 1, 2, 1);

        widget = new QWidget(frmTcpClient);
        widget->setObjectName(QString::fromUtf8("widget"));
        layTcpClient = new QHBoxLayout(widget);
        layTcpClient->setObjectName(QString::fromUtf8("layTcpClient"));
        layTcpClient->setContentsMargins(0, 0, 0, 0);
        cboxData = new QComboBox(widget);
        cboxData->setObjectName(QString::fromUtf8("cboxData"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cboxData->sizePolicy().hasHeightForWidth());
        cboxData->setSizePolicy(sizePolicy);
        cboxData->setEditable(true);

        layTcpClient->addWidget(cboxData);

        btnSend = new QPushButton(widget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setMinimumSize(QSize(80, 0));
        btnSend->setMaximumSize(QSize(80, 16777215));

        layTcpClient->addWidget(btnSend);


        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(frmTcpClient);

        QMetaObject::connectSlotsByName(frmTcpClient);
    } // setupUi

    void retranslateUi(QWidget *frmTcpClient)
    {
        frmTcpClient->setWindowTitle(QApplication::translate("frmTcpClient", "Form", nullptr));
        ckHexReceive->setText(QApplication::translate("frmTcpClient", "16\350\277\233\345\210\266\346\216\245\346\224\266", nullptr));
        ckHexSend->setText(QApplication::translate("frmTcpClient", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        ckAscii->setText(QApplication::translate("frmTcpClient", "Ascii\345\255\227\347\254\246", nullptr));
        ckShow->setText(QApplication::translate("frmTcpClient", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        ckDebug->setText(QApplication::translate("frmTcpClient", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        ckAutoSend->setText(QApplication::translate("frmTcpClient", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        labServerIP->setText(QApplication::translate("frmTcpClient", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200", nullptr));
        labServerPort->setText(QApplication::translate("frmTcpClient", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        btnConnect->setText(QApplication::translate("frmTcpClient", "\350\277\236\346\216\245", nullptr));
        btnSave->setText(QApplication::translate("frmTcpClient", "\344\277\235\345\255\230", nullptr));
        btnClear->setText(QApplication::translate("frmTcpClient", "\346\270\205\347\251\272", nullptr));
        btnSend->setText(QApplication::translate("frmTcpClient", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmTcpClient: public Ui_frmTcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTCPCLIENT_H
