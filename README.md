# CivilAviationTicketingSystem

南京邮电大学大一 C++程序设计作业

![CAT](https://i.loli.net/2021/04/12/ecmFQEv29pq5iKj.png)

## class Flight

#### 数据成员 D

\+ FNumber string

\+ Airways string

\+ StartPoint string

\+ EndPoint string

\+ PlanDepartureTime *Date

\+ PlanArrivalTime *Date

\+ Price int

\+ RemainTickit int

\+ Late bool

\+ **friend** class Admin

\- Flight \*Add(FNumber,Airways,SP,EP,PDT,PAT,Price,Tickits)

\- void Set(FNumber,Airways,SP,EP,PDT,PAT,Price,Tickits)

\- void Delete(FNumber)

## class Admin

\- void Sort(file)

\+ void Find(FNumber/SP/EP/Airways/*Date)

## class user :: Admin

\- BookNumber int

\- Trusted bool

\+ Book(FNumber,*DateNow)

\+ Refond(FNumber,*DateNow)
