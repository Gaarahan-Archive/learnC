#include<stdio.h>
int main(){
  int i,j,k;
  int count = 0;
        printf("result :\n");
  for(i = 0; i < 5;i++)
    for(j = 0; j < 5;j++)
      for(k = 0;k < 5;k++){
        if(i != j && i != k && j != k){
          printf("A:%d B:%d C:%d\t",i,j,k);
          count ++;
          if(count % 3 == 0){
            printf("\n");
          }
        }
      }

  printf("result count : %d",count);
}
