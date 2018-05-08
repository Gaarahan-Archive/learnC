#include<stdio.h>
#include<time.h>

struct date{
  int year;
  int mon;
  int day;
};

int runYear(int year){
  if((year%4 == 0&&year%100 != 0) || year%400 == 0)
    return 1;
  return 0;
}

int countDay(struct date currentDate){
  int i;
  int total = 0;
  
  for(i = 1900; i < currentDate.year;i++){
    if(runYear(i)){
      total += 1;
    }
  }

  int perMon[13] = {0,1,3,1,0,1,0,1,1,0,1,0,1};
  for(i = 1; i < currentDate.mon;i++){
    total += perMon[i];
  }
  total += currentDate.day - 1; 

  if(runYear(currentDate.year))
    total += 1;

  return total;
}
  
int main(){
  struct date today;

  printf("input which day you want to calcu : (year mon day)\n");
  scanf("%d%d%d",&today.year, &today.mon, &today.day);

  switch(countDay(today)%5){
    case 3:
    case 1:
    case 2:
      printf("time to fishing!!");
      break;

    case 0:
    case 4:
      printf("time to dry nets!!");
      break;
  }
}
