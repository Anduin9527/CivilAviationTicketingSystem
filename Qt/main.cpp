#include "Date.h"
#include "Flight.h"
#include "login.h"
#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Flight F;
  Date d1, d2;
  F.Add("XG005", "厦门航空", "福州", "杭州", &d1, &d2, 100, 1000);
  Login L;
  L.show();
  return a.exec();
}
