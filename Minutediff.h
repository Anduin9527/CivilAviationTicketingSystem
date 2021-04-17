#ifndef MINUTEDIFF_H
#define MINUTEDIFF_H

typedef struct Date{
  int year;
  int month;
  int day;
  int hour;
  int minute;
}Date;

static bool isLeapYear(int year){
  if((year%4==0&&year%100>0)||year%400==0){
    return true;
  }else{
    return false;
  }
}
static int daysInMonth(int year,int month){
  if(isLeapYear(year)){
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
      return 31;
    }
    if(month==4||month==6||month==9||month==11){
      return 30;
    }
    if(month==2){
      return 29;
    }

  }else{
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
      return 31;
    }
    if(month==4||month==6||month==9||month==11){
      return 30;
    }
    if(month==2){
      return 28;
    }
  }
}
static int daysInYear(int year, int month ,int day){
  int totalDays=0;
  for(int i=1;i<month;i++){
    totalDays+=daysInMonth(year,i);
  }
  totalDays+=day;
  return totalDays;
}
static int minutesInYear(int year, int month ,int day,int hour,int minute){
  return 1440*daysInYear(year , month , day)+60*hour+minute;
}
static int minuteDifference(Date d1,Date d2){

  if(isLeapYear(d1.year)){
    return 366*24*60*(d2.year-d1.year)+minutesInYear(d2.year,d2.month,d2.day,d2.hour,d2.minute)-minutesInYear(d1.year,d1.month,d1.day,d1.hour,d1.minute);
  }else{
    return 365*24*60*(d2.year-d1.year)+minutesInYear(d2.year,d2.month,d2.day,d2.hour,d2.minute)-minutesInYear(d1.year,d1.month,d1.day,d1.hour,d1.minute);
  }
}


#endif // MINUTEDIFF_H
