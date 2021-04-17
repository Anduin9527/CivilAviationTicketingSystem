#ifndef USER_H
#define USER_H

#include "Crasa.h"
#include "Minutediff.h"
#include <QDebug>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

typedef struct User {
  string userAccount;
  string password;
  int credit;
  int ticket;
  string airway;
} User;



string setUser(string ID, string airway, int setTicket) {//用户订票、退票所调用的函数
                                                         //根据变量status的值来返回不同的状态，由userwindow.cpp进行对应的提示文本反馈

    string status = "OK";
    // otherAirway 表示已经预定过其他航班
    // toomany 表示预定票数已达2张
    // nocredit 表示信誉过低
    // noticket 表示用户手头没有票
    bool ifcredit = true;//判断用户信誉是否为零

    if (setTicket == 1 || setTicket == -1) {//当setTicket=1时调用订票部分，-1时调用退票部分
      string temp;

      fstream acc("Account.dat", ios::in);//文件一写一读，进行文档的修改
      fstream tempFile("temp.dat", ios::out);
      if (setTicket == 1) {

        while (true) {
          if (!getline(acc, temp)) {
            break;
          }
          if (!(temp == ID)) {
            tempFile << temp << endl;
          } else {
            break;
          }
        }
        User tu;
        tu.userAccount = temp;
        tempFile << temp << endl;

        getline(acc, temp); // pwd
        tu.password = temp;
        tempFile << temp << endl;

        getline(acc, temp); // cre
        tu.credit = stoi(temp);
        tempFile << temp << endl;

        getline(acc, temp); // tick
        tu.ticket = stoi(temp);
        getline(acc, temp); // air
        tu.airway = temp;
        if (tu.credit > 0) {
          if (tu.ticket <= 1) {

            if (airway == tu.airway || tu.airway.length() <= 1) {
              tu.ticket++;
              tu.airway = airway;
              status = "OK";
            } else {
              status = "otherAirway";
            }
          } else {
            status = "toomany";
          }
        } else {
          status = "nocredit";
        }
        tempFile << tu.ticket << endl;
        tempFile << tu.airway << endl;

        while (true) {
          if (!getline(acc, temp)) {
            break;
          } else {
            tempFile << temp << endl;
          }
        }
        acc.close();
        remove("Account.dat");
        tempFile.close();
        rename("temp.dat", "Account.dat");
      }
      if (setTicket == -1) {

        while (true) {
          if (!getline(acc, temp)) {
            break;
          }
          if (!(temp == ID)) {
            tempFile << temp << endl;
          } else {
            break;
          }
        }
        User tu;
        tu.userAccount = temp;
        tempFile << temp << endl;

        getline(acc, temp); // pwd
        tu.password = temp;
        tempFile << temp << endl;

        getline(acc, temp); // cre
        tu.credit = stoi(temp);
        tempFile << temp << endl;

        getline(acc, temp); // tick
        tu.ticket = stoi(temp);
        getline(acc, temp); // air
        tu.airway = temp;
        if (tu.ticket == 1) {
          if (tu.airway.length() > 0) {
            tu.airway = "";
            tu.ticket--;
          } else {
            status = "noticket";
          }
        } else if (tu.ticket == 2) {
          if (tu.airway.length() > 0) {
            tu.ticket--;
          } else {
            status = "noticket";
          }

        } else {
          status = "noticket";
        }
        tempFile << tu.ticket << endl;
        tempFile << tu.airway << endl;

        while (true) {
          if (!getline(acc, temp)) {
            break;
          } else {
            tempFile << temp << endl;
          }
        }
        acc.close();
        remove("Account.dat");
        tempFile.close();
        rename("temp.dat", "Account.dat");
      }
    } else {
      qDebug() << "函数调用错误!";
    }
    if (!ifcredit)
      status = "nocredit";
    return status;

}
void addUser(string ID, string psw) {
  ofstream addFile("Account.dat", ios::out | ios::app);
  if (!addFile) {
    qDebug() << "open error!";
    return;
  }
  if (!isRegist(ID)) {
    addFile << ID << endl;
    addFile << psw << endl;
    addFile << "10" << endl;
    addFile << 0 << endl;
    addFile << endl;
    qDebug() << "user has been added!";
  }
  addFile.close();
}

string takeUser(string ID, string airway, bool iflate) { // iflate==1 is late
    string temp;
    string status = "OK";
    // noticket
    fstream acc("Account.dat", ios::in);
    fstream tempFile("temp.dat", ios::out);
    while (true) {
      if (!getline(acc, temp)) {
        break;
      }
      if (!(temp == ID)) {
        tempFile << temp << endl;
      } else {
        break;
      }
    }
    User tu;
    tu.userAccount = temp;
    tempFile << temp << endl;

    getline(acc, temp); // pwd
    tu.password = temp;
    tempFile << temp << endl;

    getline(acc, temp); // cre
    tu.credit = stoi(temp);
    getline(acc, temp); // tick
    tu.ticket = stoi(temp);
    getline(acc, temp); // air
    tu.airway = temp;
    if(tu.airway==airway)
    {
        if(tu.ticket>0){
            tu.ticket--;
            if (iflate) {
                tu.credit-=5;
            }
        }
        else status="noticket";
    }else status="noticket";
    tempFile << tu.credit << endl;
    tempFile << tu.ticket << endl;
    tempFile << tu.airway << endl;

    while (true) {
      if (!getline(acc, temp)) {
        break;
      } else {
        tempFile << temp << endl;
      }
    }
    acc.close();
    remove("Account.dat");
    tempFile.close();
    rename("temp.dat", "Account.dat");
    return status;

}

#endif // USER_H
