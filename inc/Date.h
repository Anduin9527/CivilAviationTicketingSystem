#include <iostream>



class Date
{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;

public:
    Date(int a = 0, int b = 0, int c = 0,int d=0, int e=0);
    ~Date();
    void getDate();
};


