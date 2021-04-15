/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QPushButton *btnDel;
    QPushButton *btnAdd;
    QPushButton *btnFind;
    QPushButton *btnSet;
    QGroupBox *groupBox_;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *editFNumber;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLineEdit *editAirways;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QLineEdit *editStartPoint;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QLineEdit *editEndPoint;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_5;
    QLineEdit *editPlanDepartureTime;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_6;
    QLineEdit *editPlanArrivalTime;
    QSpacerItem *verticalSpacer_6;
    QLabel *labelPAT;
    QLabel *label_7;
    QLineEdit *editPrice;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_8;
    QLineEdit *editRemainTickit;
    QLabel *labelPDT;
    QLabel *tip;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSort;
    QPushButton *btnFindMore;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 210, 351, 231));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(12, 12, 411, 191));
        groupBox->setAlignment(Qt::AlignCenter);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        btnDel = new QPushButton(groupBox);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));
        btnDel->setMinimumSize(QSize(171, 81));
        btnDel->setMaximumSize(QSize(171, 81));

        formLayout->setWidget(0, QFormLayout::LabelRole, btnDel);

        btnAdd = new QPushButton(groupBox);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(171, 81));
        btnAdd->setMaximumSize(QSize(171, 81));

        formLayout->setWidget(0, QFormLayout::FieldRole, btnAdd);

        btnFind = new QPushButton(groupBox);
        btnFind->setObjectName(QString::fromUtf8("btnFind"));
        btnFind->setMinimumSize(QSize(171, 81));
        btnFind->setMaximumSize(QSize(171, 81));

        formLayout->setWidget(1, QFormLayout::LabelRole, btnFind);

        btnSet = new QPushButton(groupBox);
        btnSet->setObjectName(QString::fromUtf8("btnSet"));
        btnSet->setMinimumSize(QSize(171, 81));
        btnSet->setMaximumSize(QSize(171, 81));

        formLayout->setWidget(1, QFormLayout::FieldRole, btnSet);

        groupBox_ = new QGroupBox(centralwidget);
        groupBox_->setObjectName(QString::fromUtf8("groupBox_"));
        groupBox_->setGeometry(QRect(500, 10, 261, 500));
        groupBox_->setMouseTracking(false);
        formLayout_2 = new QFormLayout(groupBox_);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label = new QLabel(groupBox_);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        editFNumber = new QLineEdit(groupBox_);
        editFNumber->setObjectName(QString::fromUtf8("editFNumber"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, editFNumber);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(1, QFormLayout::LabelRole, verticalSpacer);

        label_2 = new QLabel(groupBox_);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_2);

        editAirways = new QLineEdit(groupBox_);
        editAirways->setObjectName(QString::fromUtf8("editAirways"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, editAirways);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(3, QFormLayout::LabelRole, verticalSpacer_2);

        label_3 = new QLabel(groupBox_);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_3);

        editStartPoint = new QLineEdit(groupBox_);
        editStartPoint->setObjectName(QString::fromUtf8("editStartPoint"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, editStartPoint);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(5, QFormLayout::LabelRole, verticalSpacer_3);

        label_4 = new QLabel(groupBox_);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_4);

        editEndPoint = new QLineEdit(groupBox_);
        editEndPoint->setObjectName(QString::fromUtf8("editEndPoint"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, editEndPoint);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(7, QFormLayout::LabelRole, verticalSpacer_4);

        label_5 = new QLabel(groupBox_);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_5);

        editPlanDepartureTime = new QLineEdit(groupBox_);
        editPlanDepartureTime->setObjectName(QString::fromUtf8("editPlanDepartureTime"));

        formLayout_2->setWidget(8, QFormLayout::FieldRole, editPlanDepartureTime);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(9, QFormLayout::LabelRole, verticalSpacer_5);

        label_6 = new QLabel(groupBox_);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(10, QFormLayout::LabelRole, label_6);

        editPlanArrivalTime = new QLineEdit(groupBox_);
        editPlanArrivalTime->setObjectName(QString::fromUtf8("editPlanArrivalTime"));

        formLayout_2->setWidget(10, QFormLayout::FieldRole, editPlanArrivalTime);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(11, QFormLayout::LabelRole, verticalSpacer_6);

        labelPAT = new QLabel(groupBox_);
        labelPAT->setObjectName(QString::fromUtf8("labelPAT"));

        formLayout_2->setWidget(11, QFormLayout::FieldRole, labelPAT);

        label_7 = new QLabel(groupBox_);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(12, QFormLayout::LabelRole, label_7);

        editPrice = new QLineEdit(groupBox_);
        editPrice->setObjectName(QString::fromUtf8("editPrice"));

        formLayout_2->setWidget(12, QFormLayout::FieldRole, editPrice);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(13, QFormLayout::LabelRole, verticalSpacer_7);

        label_8 = new QLabel(groupBox_);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(14, QFormLayout::LabelRole, label_8);

        editRemainTickit = new QLineEdit(groupBox_);
        editRemainTickit->setObjectName(QString::fromUtf8("editRemainTickit"));

        formLayout_2->setWidget(14, QFormLayout::FieldRole, editRemainTickit);

        labelPDT = new QLabel(groupBox_);
        labelPDT->setObjectName(QString::fromUtf8("labelPDT"));

        formLayout_2->setWidget(9, QFormLayout::FieldRole, labelPDT);

        tip = new QLabel(centralwidget);
        tip->setObjectName(QString::fromUtf8("tip"));
        tip->setGeometry(QRect(351, 454, 111, 51));
        QFont font;
        font.setPointSize(11);
        tip->setFont(font);
        tip->setAutoFillBackground(true);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 460, 271, 83));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnSort = new QPushButton(layoutWidget);
        btnSort->setObjectName(QString::fromUtf8("btnSort"));
        btnSort->setMinimumSize(QSize(131, 81));
        btnSort->setMaximumSize(QSize(131, 81));

        horizontalLayout->addWidget(btnSort);

        btnFindMore = new QPushButton(layoutWidget);
        btnFindMore->setObjectName(QString::fromUtf8("btnFindMore"));
        btnFindMore->setMinimumSize(QSize(131, 81));
        btnFindMore->setMaximumSize(QSize(131, 81));

        horizontalLayout->addWidget(btnFindMore);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; font-size:20px; color:#d4d4d4;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-size:11pt; font-weight:600; color:#0b0b0b;\">\302\240\302\240\302\240\302\240\346\223\215\344\275\234\346\217\220\347\244\272\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Cou"
                        "rier New'; font-size:11pt; font-weight:600; color:#0b0b0b;\">\302\240\302\240\302\240\302\240\345\210\240\351\231\244\350\210\252\347\217\255\344\277\241\346\201\257\357\274\232\345\234\250\345\217\263\344\276\247\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-size:11pt; font-weight:600; color:#0b0b0b;\">\302\240\302\240\302\240\302\240\346\267\273\345\212\240\350\210\252\347\217\255\344\277\241\346\201\257\357\274\232\345\256\214\346\225\264\345\241\253\345\206\231\344\277\241\346\201\257</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-size:11pt; font-weight:600; color:#0b0b0b;\">\302\240\302\240\302\240\302\240\346\237\245\350\257\242\350\210\252\347\217\255\344\277\241\346\201\257\357"
                        "\274\232\345\234\250\345\217\263\344\276\247\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-size:11pt; font-weight:600; color:#0b0b0b;\">\302\240\302\240\302\240\302\240\346\233\264\346\226\260\350\210\252\347\217\255\344\277\241\346\201\257\357\274\232\345\256\214\346\225\264\345\241\253\345\206\231\344\277\241\346\201\257</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-size:11pt; font-weight:600; color:#0b0b0b;\">    \350\257\267\346\214\211\347\205\247</span><span style=\" font-family:'Courier New'; font-size:11pt; font-weight:600; color:#e60303;\"> </span><span style=\" font-family:'Courier New'; font-size:11pt; font-weight:600; color:#e63613;\">YYYY-MM-DD-HH-mm </span><span style="
                        "\" font-family:'Courier New'; font-size:11pt; font-weight:600; color:#0b0b0b;\">\347\232\204\346\240\274\345\274\217\350\276\223\345\205\245\346\227\266\351\227\264</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; font-size:11pt; font-weight:600; color:#0b0b0b;\"><br /></p></body></html>", nullptr));
        btnDel->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\210\252\347\217\255\344\277\241\346\201\257", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\210\252\347\217\255\344\277\241\346\201\257", nullptr));
        btnFind->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\350\210\252\347\217\255\344\277\241\346\201\257", nullptr));
        btnSet->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260\350\210\252\347\217\255\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\210\252\347\251\272\345\205\254\345\217\270\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\265\267\347\202\271\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\273\210\347\202\271\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\350\256\241\345\210\222\350\265\267\351\243\236\346\227\266\351\227\264\357\274\232", nullptr));
        editPlanDepartureTime->setInputMask(QCoreApplication::translate("MainWindow", "0000-00-00-00-00", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\350\256\241\345\210\222\345\210\260\350\276\276\346\227\266\351\227\264\357\274\232", nullptr));
        editPlanArrivalTime->setInputMask(QCoreApplication::translate("MainWindow", "0000-00-00-00-00", nullptr));
        editPlanArrivalTime->setText(QCoreApplication::translate("MainWindow", "----", nullptr));
        labelPAT->setText(QCoreApplication::translate("MainWindow", "\346\231\232\347\202\271\357\274\201", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\245\250\344\273\267\357\274\232", nullptr));
        editPrice->setInputMask(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\344\275\231\347\245\250\346\203\205\345\206\265\357\274\232", nullptr));
        labelPDT->setText(QCoreApplication::translate("MainWindow", "\346\231\232\347\202\271\357\274\201", nullptr));
        tip->setText(QString());
        btnSort->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\346\227\245\346\234\237\346\216\222\345\272\217\346\226\207\344\273\266", nullptr));
        btnFindMore->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\346\233\264\345\244\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
