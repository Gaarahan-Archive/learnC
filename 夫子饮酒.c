#include<stdio.h>

int drink(int n);
int count(int arr[], int n);

int main(){
  int n;
  printf("input n:");
  scanf("%d",&n);

  int res = drink(n);
  printf("%d",res);
}

int drink(int n){
  int arr[20] = {0};
  int i,j;
  for(i = 0; i < n;i++){
    //第一棵树
    if(i == 0) {
      for(j = 0; j < n ;j ++){
        arr[j] = 1;
      }
    }
    //第n棵树
    else if(i == n - 1){
      if(arr[n - 1] == 0)
        arr[n - 1] = 1;
      else
        arr[n - 1] = 0;
    }
    else{
      for(j = 0;j < n;j++){
        if( (j + 1)%(i + 1) == 0 ){
          if(arr[j] == 1)
            arr[j] = 0;
          else
            arr[j] = 1;
        }
      }
    }
  }
  return count(arr,n);
}

int count(int arr[], int n){
  int i;
  int cou = 0;
  for(i = 0;i < n; i++ ){
    if(arr[i] == 1){
      cou ++;
    }
  } 
  return cou;
}
