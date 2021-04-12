# CivilAviationTicketingSystem
南京邮电大学大一C++程序设计作业

## class Flight

#### 数据成员

\+ FNumber string

\+ Airways string 

\+ startPoint string

\+ endPoint string

\+ PlanDepartureTime Date

\+ PlanArrivalTime Date

\+ Price int 

\+ RemainTickit int

\+ Late bool

\+ **friend** class Admin

\- void Add(FNumber,Airways,SP,EP,PDT,PAT,Price,Tickits)

\- void Set(FNumber,Airways,SP,EP,PDT,PAT,Price,Tickits)

\- void Delete(FNumber)

## class Admin

\- void Sort(file)

\+ void Find(FNumber/SP/EP/Airways/Date)

## class user :: Admin

\- BookNumber int

\- Trusted bool

\+ Book(FNumber,DateNow)

\+ Refond(FNumber,DateNow)

