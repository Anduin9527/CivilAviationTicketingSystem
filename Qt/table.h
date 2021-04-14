#ifndef TABLE_H
#define TABLE_H

#include <QWidget>

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();

private:
    Ui::Table *ui;
};

#endif // TABLE_H
