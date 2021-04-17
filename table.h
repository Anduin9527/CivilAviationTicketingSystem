#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>

namespace Ui {
class Table;
}

class Table : public QMainWindow
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();

private:
    Ui::Table *ui;
};

#endif // TABLE_H
