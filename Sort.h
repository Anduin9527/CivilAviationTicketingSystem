#include <string>
using namespace std;
typedef struct flight //结构体数组排序
{
  string FNumber;
  string Airways;
  string StartPoint;
  string EndPoint;
  string PlanDepartureTime;
  string PlanArrivalTime;
  string Price;
  string RemainTickit;
  string Late;
} F;

bool Cmp(const F &a, const F &b);
void Fin(int num);
int Sort();
