/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *name;
    QLineEdit *password;
    QPushButton *btn_Admin;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_User;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(600, 480);
        Login->setMinimumSize(QSize(600, 480));
        Login->setMaximumSize(QSize(600, 480));
        widget = new QWidget(Login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 270, 601, 97));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(279, 23));
        name->setMaximumSize(QSize(279, 23));

        verticalLayout->addWidget(name);

        password = new QLineEdit(groupBox);
        password->setObjectName(QString::fromUtf8("password"));
        password->setMinimumSize(QSize(279, 23));
        password->setMaximumSize(QSize(279, 23));
        password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password);

        btn_Admin = new QPushButton(groupBox);
        btn_Admin->setObjectName(QString::fromUtf8("btn_Admin"));
        btn_Admin->setMinimumSize(QSize(279, 24));
        btn_Admin->setMaximumSize(QSize(279, 24));

        verticalLayout->addWidget(btn_Admin);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        widget1 = new QWidget(Login);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(0, 102, 601, 133));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_User = new QPushButton(widget1);
        btn_User->setObjectName(QString::fromUtf8("btn_User"));
        btn_User->setMinimumSize(QSize(331, 131));
        btn_User->setMaximumSize(QSize(331, 131));

        horizontalLayout_2->addWidget(btn_User);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        name->setText(QString());
        name->setPlaceholderText(QCoreApplication::translate("Login", "\347\256\241\347\220\206\345\221\230\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        password->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("Login", "\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201\357\274\232", nullptr));
        btn_Admin->setText(QCoreApplication::translate("Login", "\347\256\241\347\220\206\345\221\230\345\205\245\345\217\243", nullptr));
        btn_User->setText(QCoreApplication::translate("Login", "\346\210\221\346\230\257\346\227\205\345\256\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
