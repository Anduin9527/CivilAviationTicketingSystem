#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>
#include <QDebug>
#include "Minutediff.h"
using namespace std;

typedef struct User{
    string userAccount;
    string password;
    int credit;
    int ticket;
    string airway;
}User;

string setUser(string ID,string airway,int setTicket){
    string status="OK";
    //otherAirway
    //toomany
    //nocredit
    //noticket
    bool ifcredit=true;

    if(setTicket==1||setTicket==-1)
    {
        string temp;

        fstream acc("Account.dat",ios::in);
        fstream tempFile("temp.dat",ios::out);
        if(setTicket==1){

            while(true){
                if(!getline(acc,temp)){
                    break;
                }
                if(!(temp==ID)){
                    tempFile<<temp<<endl;
                }else{
                    break;
                }
            }
            tempFile<<temp<<endl;//write target ID
            getline(acc,temp);
            tempFile<<temp<<endl;//write target pwd
            getline(acc,temp);  //read credit
            if(stoi(temp)){
                tempFile<<temp<<endl;
            }else{
                tempFile<<temp<<endl;
                status="nocredit";
                ifcredit=false;
            }
            getline(acc,temp);  //read ticket
            if(stoi(temp)>1){
                status="toomany";
                tempFile<<temp<<endl;
            }else{
                if(ifcredit)
                {tempFile<<stoi(temp)+1<<endl;}
                else{
                    status="nocredit";
                }
            }
            getline(acc,temp);  //read airway
            if(temp.length()>0){
                status="otherAirway";
                tempFile<<temp<<endl;
            }else{
                tempFile<<airway<<endl;
            }

            while (true)
            {
              if (!getline(acc, temp))
              {
                break;
              }
              else
              {
                  tempFile << temp << endl;
              }
            }
            acc.close();
            remove("Account.dat");
            tempFile.close();
            rename("temp.dat", "Account.dat");


        }
        if(setTicket==-1){
            int restTicket=0;
            while(true){
                if(!getline(acc,temp)){
                    break;
                }
                if(!(temp==ID)){
                    tempFile<<temp<<endl;
                }else{
                    break;
                }
            }
            tempFile<<temp<<endl;//write target ID
            getline(acc,temp);
            tempFile<<temp<<endl;//write target pwd
            getline(acc,temp);//read credit
            tempFile<<temp<<endl;
            getline(acc,temp);//read ticket
            if(stoi(temp)>0){
                tempFile<<to_string(stoi(temp)-1)<<endl;
                restTicket=stoi(temp)-1;
            }else{
                status="noticket";
                tempFile<<temp<<endl;
            }
            getline(acc,temp);//read airway
            if(restTicket>0){
                tempFile<<airway<<endl;
            }else{
                tempFile<<endl;
            }

            while (true)
            {
              if (!getline(acc, temp))
              {
                break;
              }
              else
              {
                  tempFile << temp << endl;
              }
            }
            acc.close();
            remove("Account.dat");
            tempFile.close();
            rename("temp.dat", "Account.dat");
        }
    }else{
        qDebug() << "函数调用错误!";
    }
    if(!ifcredit) status= "nocredit";
    return status;
}
void addUser(string ID,string psw){
    fstream addFile("Account.dat",ios::out|ios::app);
    if(!addFile) {
        qDebug() << "open error!";
        return ;
    }
    addFile<<ID<<endl;
    addFile<<psw<<endl;
    addFile<<"1"<<endl;
    addFile<<0<<endl;
    addFile<<endl;
    qDebug() << "user has been added!";
    addFile.close();
}
string takeUser(string ID,string airway,bool iflate){//iflate==1 is late
    int restTicket=0;
    string temp;
    string status="OK";
    //noticket
    fstream acc("Account.dat",ios::in);
    fstream tempFile("temp.dat",ios::out);
    while(true){
        if(!getline(acc,temp)){
            break;
        }
        if(!(temp==ID)){
            tempFile<<temp<<endl;
        }else{
            break;
        }
    }
    tempFile<<temp<<endl;//write target ID
    getline(acc,temp);  //read pwd
    tempFile<<temp<<endl;//write target pwd
    getline(acc,temp);//read credit
    if(iflate){
        tempFile<<to_string(0)<<endl;
    }else{
        tempFile<<to_string(1)<<endl;
    }
    getline(acc,temp);//read ticket
    if(stoi(temp)>0){
        tempFile<<to_string(stoi(temp)-1)<<endl;
        restTicket=stoi(temp)-1;
    }else{
        status="noticket";
        tempFile<<temp<<endl;
    }
    getline(acc,temp);//read airway
    if(restTicket>0){
        tempFile<<airway<<endl;
    }else{
        tempFile<<endl;
    }

    while (true)
    {
      if (!getline(acc, temp))
      {
        break;
      }
      else
      {
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
