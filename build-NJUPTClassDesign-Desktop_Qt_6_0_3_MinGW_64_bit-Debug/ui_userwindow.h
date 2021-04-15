/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_10;
    QLineEdit *editFNumber;
    QLineEdit *editAirways;
    QLineEdit *editStartPoint;
    QLineEdit *editEndPoint;
    QLineEdit *editPlanDepartureTime;
    QLineEdit *editPlanArrivalTime;
    QLineEdit *editPrice;
    QLineEdit *editRemainTickit;
    QLabel *labelPDT;
    QLabel *labelPAT;
    QLabel *tip;
    QPushButton *btnFindMore;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupLogin;
    QGridLayout *gridLayout;
    QPushButton *btnLogin;
    QLineEdit *editPasswd;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnRegist;
    QLineEdit *editName;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox1;
    QGridLayout *gridLayout_2;
    QPushButton *btnBook;
    QPushButton *btnTake;
    QPushButton *btnRefund;
    QPushButton *btnFind;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(800, 600);
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(470, 20, 261, 500));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(1, QFormLayout::LabelRole, verticalSpacer);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(3, QFormLayout::LabelRole, verticalSpacer_2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(5, QFormLayout::LabelRole, verticalSpacer_3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(7, QFormLayout::LabelRole, verticalSpacer_4);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_7);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(9, QFormLayout::LabelRole, verticalSpacer_5);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(10, QFormLayout::LabelRole, label_8);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(11, QFormLayout::LabelRole, verticalSpacer_6);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(12, QFormLayout::LabelRole, label_9);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(13, QFormLayout::LabelRole, verticalSpacer_7);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(14, QFormLayout::LabelRole, label_10);

        editFNumber = new QLineEdit(groupBox);
        editFNumber->setObjectName(QString::fromUtf8("editFNumber"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, editFNumber);

        editAirways = new QLineEdit(groupBox);
        editAirways->setObjectName(QString::fromUtf8("editAirways"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, editAirways);

        editStartPoint = new QLineEdit(groupBox);
        editStartPoint->setObjectName(QString::fromUtf8("editStartPoint"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, editStartPoint);

        editEndPoint = new QLineEdit(groupBox);
        editEndPoint->setObjectName(QString::fromUtf8("editEndPoint"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, editEndPoint);

        editPlanDepartureTime = new QLineEdit(groupBox);
        editPlanDepartureTime->setObjectName(QString::fromUtf8("editPlanDepartureTime"));

        formLayout_2->setWidget(8, QFormLayout::FieldRole, editPlanDepartureTime);

        editPlanArrivalTime = new QLineEdit(groupBox);
        editPlanArrivalTime->setObjectName(QString::fromUtf8("editPlanArrivalTime"));

        formLayout_2->setWidget(10, QFormLayout::FieldRole, editPlanArrivalTime);

        editPrice = new QLineEdit(groupBox);
        editPrice->setObjectName(QString::fromUtf8("editPrice"));

        formLayout_2->setWidget(12, QFormLayout::FieldRole, editPrice);

        editRemainTickit = new QLineEdit(groupBox);
        editRemainTickit->setObjectName(QString::fromUtf8("editRemainTickit"));

        formLayout_2->setWidget(14, QFormLayout::FieldRole, editRemainTickit);

        labelPDT = new QLabel(groupBox);
        labelPDT->setObjectName(QString::fromUtf8("labelPDT"));

        formLayout_2->setWidget(9, QFormLayout::FieldRole, labelPDT);

        labelPAT = new QLabel(groupBox);
        labelPAT->setObjectName(QString::fromUtf8("labelPAT"));

        formLayout_2->setWidget(11, QFormLayout::FieldRole, labelPAT);

        tip = new QLabel(centralwidget);
        tip->setObjectName(QString::fromUtf8("tip"));
        tip->setGeometry(QRect(40, 520, 711, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(11);
        font.setBold(true);
        font.setUnderline(false);
        tip->setFont(font);
        btnFindMore = new QPushButton(centralwidget);
        btnFindMore->setObjectName(QString::fromUtf8("btnFindMore"));
        btnFindMore->setGeometry(QRect(340, 360, 131, 121));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 339, 503));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupLogin = new QGroupBox(layoutWidget);
        groupLogin->setObjectName(QString::fromUtf8("groupLogin"));
        gridLayout = new QGridLayout(groupLogin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnLogin = new QPushButton(groupLogin);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));

        gridLayout->addWidget(btnLogin, 2, 1, 1, 1);

        editPasswd = new QLineEdit(groupLogin);
        editPasswd->setObjectName(QString::fromUtf8("editPasswd"));
        editPasswd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(editPasswd, 1, 1, 1, 1);

        label = new QLabel(groupLogin);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupLogin);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        btnRegist = new QPushButton(groupLogin);
        btnRegist->setObjectName(QString::fromUtf8("btnRegist"));

        gridLayout->addWidget(btnRegist, 2, 0, 1, 1);

        editName = new QLineEdit(groupLogin);
        editName->setObjectName(QString::fromUtf8("editName"));
        editName->setInputMask(QString::fromUtf8(""));

        gridLayout->addWidget(editName, 0, 1, 1, 1);


        verticalLayout->addWidget(groupLogin);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        groupBox1 = new QGroupBox(layoutWidget);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        gridLayout_2 = new QGridLayout(groupBox1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btnBook = new QPushButton(groupBox1);
        btnBook->setObjectName(QString::fromUtf8("btnBook"));
        btnBook->setEnabled(false);
        btnBook->setMinimumSize(QSize(151, 71));
        btnBook->setMaximumSize(QSize(151, 71));

        gridLayout_2->addWidget(btnBook, 0, 0, 1, 1);

        btnTake = new QPushButton(groupBox1);
        btnTake->setObjectName(QString::fromUtf8("btnTake"));
        btnTake->setEnabled(false);
        btnTake->setMinimumSize(QSize(151, 71));
        btnTake->setMaximumSize(QSize(151, 71));

        gridLayout_2->addWidget(btnTake, 0, 1, 1, 1);

        btnRefund = new QPushButton(groupBox1);
        btnRefund->setObjectName(QString::fromUtf8("btnRefund"));
        btnRefund->setEnabled(false);
        btnRefund->setMinimumSize(QSize(151, 71));
        btnRefund->setMaximumSize(QSize(151, 71));

        gridLayout_2->addWidget(btnRefund, 1, 0, 1, 1);

        btnFind = new QPushButton(groupBox1);
        btnFind->setObjectName(QString::fromUtf8("btnFind"));
        btnFind->setMinimumSize(QSize(151, 71));
        btnFind->setMaximumSize(QSize(151, 71));

        gridLayout_2->addWidget(btnFind, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox1);

        UserWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UserWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UserWindow->setStatusBar(statusbar);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("UserWindow", "\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("UserWindow", "\350\210\252\347\251\272\345\205\254\345\217\270\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("UserWindow", "\350\265\267\347\202\271\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("UserWindow", "\347\273\210\347\202\271\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("UserWindow", "\350\256\241\345\210\222\350\265\267\351\243\236\346\227\266\351\227\264\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("UserWindow", "\350\256\241\345\210\222\345\210\260\350\276\276\346\227\266\351\227\264\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("UserWindow", "\347\245\250\344\273\267\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("UserWindow", "\344\275\231\347\245\250\346\203\205\345\206\265\357\274\232", nullptr));
        labelPDT->setText(QString());
        labelPAT->setText(QString());
        tip->setText(QCoreApplication::translate("UserWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\345\215\227\351\202\256\350\210\252\347\251\272\347\245\250\345\212\241\347\263\273\347\273\237\357\274\201", nullptr));
        btnFindMore->setText(QCoreApplication::translate("UserWindow", "\346\237\245\350\257\242\346\233\264\345\244\232", nullptr));
        btnLogin->setText(QCoreApplication::translate("UserWindow", "\347\231\273\345\275\225", nullptr));
        editPasswd->setInputMask(QString());
        label->setText(QCoreApplication::translate("UserWindow", "\350\264\246\346\210\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        btnRegist->setText(QCoreApplication::translate("UserWindow", "\346\263\250\345\206\214", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("UserWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\350\257\267\347\231\273\345\275\225\346\210\226\346\263\250\345\206\214\345\220\216\350\277\233\350\241\214\346\233\264\345\244\232\346\223\215\344\275\234</span></p></body></html>", nullptr));
        btnBook->setText(QCoreApplication::translate("UserWindow", "\350\256\242\347\245\250", nullptr));
        btnTake->setText(QCoreApplication::translate("UserWindow", "\345\217\226\347\245\250", nullptr));
        btnRefund->setText(QCoreApplication::translate("UserWindow", "\351\200\200\347\245\250", nullptr));
        btnFind->setText(QCoreApplication::translate("UserWindow", "\346\237\245\350\257\242\350\210\252\347\217\255\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
