/********************************************************************************
** Form generated from reading UI file 'frmtcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTCPSERVER_H
#define UI_FRMTCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmTcpServer
{
public:
    QGridLayout *gridLayout;
    QTextEdit *txtMain;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *ckHexReceive;
    QCheckBox *ckHexSend;
    QCheckBox *ckAscii;
    QCheckBox *ckShow;
    QCheckBox *ckDebug;
    QCheckBox *ckAutoSend;
    QComboBox *cboxInterval;
    QLabel *labListenPort;
    QLineEdit *txtListenPort;
    QPushButton *btnListen;
    QPushButton *btnSave;
    QPushButton *btnClear;
    QLabel *labCount;
    QListWidget *listWidget;
    QCheckBox *ckAll;
    QWidget *widget;
    QHBoxLayout *layTcpServer;
    QComboBox *cboxData;
    QPushButton *btnSend;

    void setupUi(QWidget *frmTcpServer)
    {
        if (frmTcpServer->objectName().isEmpty())
            frmTcpServer->setObjectName(QString::fromUtf8("frmTcpServer"));
        frmTcpServer->resize(800, 600);
        gridLayout = new QGridLayout(frmTcpServer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        txtMain = new QTextEdit(frmTcpServer);
        txtMain->setObjectName(QString::fromUtf8("txtMain"));
        txtMain->setReadOnly(true);

        gridLayout->addWidget(txtMain, 0, 0, 1, 1);

        frame = new QFrame(frmTcpServer);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(170, 0));
        frame->setMaximumSize(QSize(170, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 9, 9, 9);
        ckHexReceive = new QCheckBox(frame);
        ckHexReceive->setObjectName(QString::fromUtf8("ckHexReceive"));

        verticalLayout_3->addWidget(ckHexReceive);

        ckHexSend = new QCheckBox(frame);
        ckHexSend->setObjectName(QString::fromUtf8("ckHexSend"));

        verticalLayout_3->addWidget(ckHexSend);

        ckAscii = new QCheckBox(frame);
        ckAscii->setObjectName(QString::fromUtf8("ckAscii"));

        verticalLayout_3->addWidget(ckAscii);

        ckShow = new QCheckBox(frame);
        ckShow->setObjectName(QString::fromUtf8("ckShow"));

        verticalLayout_3->addWidget(ckShow);

        ckDebug = new QCheckBox(frame);
        ckDebug->setObjectName(QString::fromUtf8("ckDebug"));

        verticalLayout_3->addWidget(ckDebug);

        ckAutoSend = new QCheckBox(frame);
        ckAutoSend->setObjectName(QString::fromUtf8("ckAutoSend"));

        verticalLayout_3->addWidget(ckAutoSend);

        cboxInterval = new QComboBox(frame);
        cboxInterval->setObjectName(QString::fromUtf8("cboxInterval"));

        verticalLayout_3->addWidget(cboxInterval);

        labListenPort = new QLabel(frame);
        labListenPort->setObjectName(QString::fromUtf8("labListenPort"));

        verticalLayout_3->addWidget(labListenPort);

        txtListenPort = new QLineEdit(frame);
        txtListenPort->setObjectName(QString::fromUtf8("txtListenPort"));

        verticalLayout_3->addWidget(txtListenPort);

        btnListen = new QPushButton(frame);
        btnListen->setObjectName(QString::fromUtf8("btnListen"));

        verticalLayout_3->addWidget(btnListen);

        btnSave = new QPushButton(frame);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        verticalLayout_3->addWidget(btnSave);

        btnClear = new QPushButton(frame);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        verticalLayout_3->addWidget(btnClear);

        labCount = new QLabel(frame);
        labCount->setObjectName(QString::fromUtf8("labCount"));

        verticalLayout_3->addWidget(labCount);

        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_3->addWidget(listWidget);

        ckAll = new QCheckBox(frame);
        ckAll->setObjectName(QString::fromUtf8("ckAll"));

        verticalLayout_3->addWidget(ckAll);


        gridLayout->addWidget(frame, 0, 1, 2, 1);

        widget = new QWidget(frmTcpServer);
        widget->setObjectName(QString::fromUtf8("widget"));
        layTcpServer = new QHBoxLayout(widget);
        layTcpServer->setObjectName(QString::fromUtf8("layTcpServer"));
        layTcpServer->setContentsMargins(0, 0, 0, 0);
        cboxData = new QComboBox(widget);
        cboxData->setObjectName(QString::fromUtf8("cboxData"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cboxData->sizePolicy().hasHeightForWidth());
        cboxData->setSizePolicy(sizePolicy);
        cboxData->setEditable(true);

        layTcpServer->addWidget(cboxData);

        btnSend = new QPushButton(widget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setMinimumSize(QSize(80, 0));
        btnSend->setMaximumSize(QSize(80, 16777215));

        layTcpServer->addWidget(btnSend);


        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(frmTcpServer);

        QMetaObject::connectSlotsByName(frmTcpServer);
    } // setupUi

    void retranslateUi(QWidget *frmTcpServer)
    {
        frmTcpServer->setWindowTitle(QApplication::translate("frmTcpServer", "Form", nullptr));
        ckHexReceive->setText(QApplication::translate("frmTcpServer", "16\350\277\233\345\210\266\346\216\245\346\224\266", nullptr));
        ckHexSend->setText(QApplication::translate("frmTcpServer", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        ckAscii->setText(QApplication::translate("frmTcpServer", "Ascii\345\255\227\347\254\246", nullptr));
        ckShow->setText(QApplication::translate("frmTcpServer", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        ckDebug->setText(QApplication::translate("frmTcpServer", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        ckAutoSend->setText(QApplication::translate("frmTcpServer", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        labListenPort->setText(QApplication::translate("frmTcpServer", "\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        btnListen->setText(QApplication::translate("frmTcpServer", "\347\233\221\345\220\254", nullptr));
        btnSave->setText(QApplication::translate("frmTcpServer", "\344\277\235\345\255\230", nullptr));
        btnClear->setText(QApplication::translate("frmTcpServer", "\346\270\205\347\251\272", nullptr));
        labCount->setText(QApplication::translate("frmTcpServer", "\345\267\262\350\277\236\346\216\245\345\256\242\346\210\267\347\253\257\345\205\261 0 \344\270\252", nullptr));
        ckAll->setText(QApplication::translate("frmTcpServer", "\345\257\271\345\205\250\351\203\250\345\256\242\346\210\267\347\253\257\345\217\221\351\200\201", nullptr));
        btnSend->setText(QApplication::translate("frmTcpServer", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmTcpServer: public Ui_frmTcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTCPSERVER_H
