/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Table
{
public:
    QWidget *centralwidget;
    QTableWidget *table;
    QPushButton *btn;
    QCheckBox *checkDate;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *editDate;
    QLineEdit *editStart;
    QLineEdit *editEnd;
    QLineEdit *editAirways;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Table)
    {
        if (Table->objectName().isEmpty())
            Table->setObjectName(QString::fromUtf8("Table"));
        Table->resize(800, 600);
        Table->setMinimumSize(QSize(800, 600));
        Table->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(Table);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        table = new QTableWidget(centralwidget);
        if (table->columnCount() < 9)
            table->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(0, 0, 801, 411));
        table->setMinimumSize(QSize(801, 411));
        table->setMaximumSize(QSize(801, 411));
        btn = new QPushButton(centralwidget);
        btn->setObjectName(QString::fromUtf8("btn"));
        btn->setGeometry(QRect(480, 470, 181, 61));
        checkDate = new QCheckBox(centralwidget);
        checkDate->setObjectName(QString::fromUtf8("checkDate"));
        checkDate->setGeometry(QRect(20, 440, 93, 21));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 430, 291, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        editDate = new QLineEdit(layoutWidget);
        editDate->setObjectName(QString::fromUtf8("editDate"));

        verticalLayout->addWidget(editDate);

        editStart = new QLineEdit(layoutWidget);
        editStart->setObjectName(QString::fromUtf8("editStart"));

        verticalLayout->addWidget(editStart);

        editEnd = new QLineEdit(layoutWidget);
        editEnd->setObjectName(QString::fromUtf8("editEnd"));

        verticalLayout->addWidget(editEnd);

        editAirways = new QLineEdit(layoutWidget);
        editAirways->setObjectName(QString::fromUtf8("editAirways"));

        verticalLayout->addWidget(editAirways);

        Table->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Table);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Table->setStatusBar(statusbar);

        retranslateUi(Table);

        QMetaObject::connectSlotsByName(Table);
    } // setupUi

    void retranslateUi(QMainWindow *Table)
    {
        Table->setWindowTitle(QCoreApplication::translate("Table", "\350\257\246\347\273\206\345\210\227\350\241\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Table", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Table", "\350\210\252\347\251\272\345\205\254\345\217\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Table", "\345\207\272\345\217\221\345\234\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Table", "\347\233\256\347\232\204\345\234\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Table", "\351\242\204\350\256\241\350\265\267\351\243\236\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Table", "\351\242\204\350\256\241\345\210\260\350\276\276\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Table", "\344\273\267\346\240\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Table", "\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Table", "\346\230\257\345\220\246\346\231\232\347\202\271", nullptr));
        btn->setText(QCoreApplication::translate("Table", "\346\237\245\350\257\242", nullptr));
        checkDate->setText(QString());
        editDate->setInputMask(QCoreApplication::translate("Table", "0000-00-00-00-00", nullptr));
        editDate->setPlaceholderText(QCoreApplication::translate("Table", "YYYY-MM-DD-HH-mm", nullptr));
        editStart->setText(QString());
        editStart->setPlaceholderText(QCoreApplication::translate("Table", "\345\207\272\345\217\221\345\234\260", nullptr));
        editEnd->setText(QString());
        editEnd->setPlaceholderText(QCoreApplication::translate("Table", "\347\233\256\347\232\204\345\234\260", nullptr));
        editAirways->setText(QString());
        editAirways->setPlaceholderText(QCoreApplication::translate("Table", "\350\210\252\347\251\272\345\205\254\345\217\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Table: public Ui_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
