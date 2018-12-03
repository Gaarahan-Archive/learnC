#include<stdio.h>
int main(){
  int s = 0,n;
  for(n = 0; n < 4;n++){
    switch(n){
      default: s+=4;
      case 1 : s+=1; break;
      case 2 : s+=2;break;
      case 3 : s+=3;
    }
    printf("%d\t%d\n",s,n);
  }
  printf("%d\n",s);
}
