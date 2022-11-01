/********************************************************************************
** Form generated from reading UI file 'frmudpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMUDPSERVER_H
#define UI_FRMUDPSERVER_H

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

class Ui_frmUdpServer
{
public:
    QGridLayout *gridLayout;
    QTextEdit *txtMain;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
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
    QLabel *labListenPort;
    QLineEdit *txtListenPort;
    QPushButton *btnListen;
    QPushButton *btnSave;
    QPushButton *btnClear;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *layUdpServer;
    QComboBox *cboxData;
    QPushButton *btnSend;

    void setupUi(QWidget *frmUdpServer)
    {
        if (frmUdpServer->objectName().isEmpty())
            frmUdpServer->setObjectName(QString::fromUtf8("frmUdpServer"));
        frmUdpServer->resize(800, 600);
        gridLayout = new QGridLayout(frmUdpServer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        txtMain = new QTextEdit(frmUdpServer);
        txtMain->setObjectName(QString::fromUtf8("txtMain"));
        txtMain->setReadOnly(true);

        gridLayout->addWidget(txtMain, 0, 0, 1, 1);

        frame = new QFrame(frmUdpServer);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(170, 0));
        frame->setMaximumSize(QSize(170, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ckHexReceive = new QCheckBox(frame);
        ckHexReceive->setObjectName(QString::fromUtf8("ckHexReceive"));

        verticalLayout_2->addWidget(ckHexReceive);

        ckHexSend = new QCheckBox(frame);
        ckHexSend->setObjectName(QString::fromUtf8("ckHexSend"));

        verticalLayout_2->addWidget(ckHexSend);

        ckAscii = new QCheckBox(frame);
        ckAscii->setObjectName(QString::fromUtf8("ckAscii"));

        verticalLayout_2->addWidget(ckAscii);

        ckShow = new QCheckBox(frame);
        ckShow->setObjectName(QString::fromUtf8("ckShow"));

        verticalLayout_2->addWidget(ckShow);

        ckDebug = new QCheckBox(frame);
        ckDebug->setObjectName(QString::fromUtf8("ckDebug"));

        verticalLayout_2->addWidget(ckDebug);

        ckAutoSend = new QCheckBox(frame);
        ckAutoSend->setObjectName(QString::fromUtf8("ckAutoSend"));

        verticalLayout_2->addWidget(ckAutoSend);

        cboxInterval = new QComboBox(frame);
        cboxInterval->setObjectName(QString::fromUtf8("cboxInterval"));

        verticalLayout_2->addWidget(cboxInterval);

        labServerIP = new QLabel(frame);
        labServerIP->setObjectName(QString::fromUtf8("labServerIP"));

        verticalLayout_2->addWidget(labServerIP);

        txtServerIP = new QLineEdit(frame);
        txtServerIP->setObjectName(QString::fromUtf8("txtServerIP"));

        verticalLayout_2->addWidget(txtServerIP);

        labServerPort = new QLabel(frame);
        labServerPort->setObjectName(QString::fromUtf8("labServerPort"));

        verticalLayout_2->addWidget(labServerPort);

        txtServerPort = new QLineEdit(frame);
        txtServerPort->setObjectName(QString::fromUtf8("txtServerPort"));

        verticalLayout_2->addWidget(txtServerPort);

        labListenPort = new QLabel(frame);
        labListenPort->setObjectName(QString::fromUtf8("labListenPort"));

        verticalLayout_2->addWidget(labListenPort);

        txtListenPort = new QLineEdit(frame);
        txtListenPort->setObjectName(QString::fromUtf8("txtListenPort"));

        verticalLayout_2->addWidget(txtListenPort);

        btnListen = new QPushButton(frame);
        btnListen->setObjectName(QString::fromUtf8("btnListen"));

        verticalLayout_2->addWidget(btnListen);

        btnSave = new QPushButton(frame);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        verticalLayout_2->addWidget(btnSave);

        btnClear = new QPushButton(frame);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        verticalLayout_2->addWidget(btnClear);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addWidget(frame, 0, 1, 2, 1);

        widget = new QWidget(frmUdpServer);
        widget->setObjectName(QString::fromUtf8("widget"));
        layUdpServer = new QHBoxLayout(widget);
        layUdpServer->setObjectName(QString::fromUtf8("layUdpServer"));
        layUdpServer->setContentsMargins(0, 0, 0, 0);
        cboxData = new QComboBox(widget);
        cboxData->setObjectName(QString::fromUtf8("cboxData"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cboxData->sizePolicy().hasHeightForWidth());
        cboxData->setSizePolicy(sizePolicy);
        cboxData->setEditable(true);

        layUdpServer->addWidget(cboxData);

        btnSend = new QPushButton(widget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setMinimumSize(QSize(80, 0));
        btnSend->setMaximumSize(QSize(80, 16777215));

        layUdpServer->addWidget(btnSend);


        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(frmUdpServer);

        QMetaObject::connectSlotsByName(frmUdpServer);
    } // setupUi

    void retranslateUi(QWidget *frmUdpServer)
    {
        frmUdpServer->setWindowTitle(QApplication::translate("frmUdpServer", "Form", nullptr));
        ckHexReceive->setText(QApplication::translate("frmUdpServer", "16\350\277\233\345\210\266\346\216\245\346\224\266", nullptr));
        ckHexSend->setText(QApplication::translate("frmUdpServer", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        ckAscii->setText(QApplication::translate("frmUdpServer", "Ascii\345\255\227\347\254\246", nullptr));
        ckShow->setText(QApplication::translate("frmUdpServer", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        ckDebug->setText(QApplication::translate("frmUdpServer", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        ckAutoSend->setText(QApplication::translate("frmUdpServer", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        labServerIP->setText(QApplication::translate("frmUdpServer", "\350\277\234\347\250\213IP\345\234\260\345\235\200", nullptr));
        labServerPort->setText(QApplication::translate("frmUdpServer", "\350\277\234\347\250\213\347\253\257\345\217\243", nullptr));
        labListenPort->setText(QApplication::translate("frmUdpServer", "\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        btnListen->setText(QApplication::translate("frmUdpServer", "\347\233\221\345\220\254", nullptr));
        btnSave->setText(QApplication::translate("frmUdpServer", "\344\277\235\345\255\230", nullptr));
        btnClear->setText(QApplication::translate("frmUdpServer", "\346\270\205\347\251\272", nullptr));
        btnSend->setText(QApplication::translate("frmUdpServer", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmUdpServer: public Ui_frmUdpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMUDPSERVER_H
