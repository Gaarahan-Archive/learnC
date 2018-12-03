#include<stdio.h>
int main(){
  int i,j;
  int num[3];
  int k = 0;
  int count = 0;
  for(i = 1; i <= 4;i++){
    k=0;
    for(j = 1; j <= 4;j++){
      if(j != i){ num[k++] = j; }
    }

    count += 6;
    printf("%d\n",num[0]*100 + num[1]*10 + num[2]);
    printf("%d\n",num[0]*100 + num[2]*10 + num[1]);
    printf("%d\n",num[1]*100 + num[0]*10 + num[2]);
    printf("%d\n",num[1]*100 + num[2]*10 + num[0]);
    printf("%d\n",num[2]*100 + num[1]*10 + num[0]);
    printf("%d\n",num[2]*100 + num[0]*10 + num[1]);
  }
  
  printf("result count : %d",count);
}
