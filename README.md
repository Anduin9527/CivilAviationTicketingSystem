# CivilAviationTicketingSystem

南京邮电大学大一 C++程序设计作业

![CAT](https://i.loli.net/2021/04/12/ecmFQEv29pq5iKj.png)

## TO DO

- [ ] Date类
  - [ ] 判断日期格式
- [x] Flight类
  - [x] Add
  - [x] Delete
  - [x] Set
  - [x] Find
  - [x] 晚点
- [ ] UI
  - [x] Login
  - [x] Admin
  - [x] user
- [ ] Sort
- [ ] 票务管理
  - [ ] 退票
  - [ ] 订票
  - [ ] 取票
  - [ ] 诚信系统

## class Flight

#### 数据成员 

\+ FNumber string

\+ Airways string

\+ StartPoint string

\+ EndPoint string

\+ PlanDepartureTime *Date

\+ PlanArrivalTime *Date

\+ Price int

\+ RemainTickit int

\+ Late bool

#### 函数成员

\+ void Add(&Flight)

\+ void Set(&Flight)

\+ void Delete(FNumber)


