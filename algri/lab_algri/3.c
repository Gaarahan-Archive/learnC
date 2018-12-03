#include<stdio.h>
#include<string.h>
int main(){
  char str[50],result[50];
  int len,i;
  int start,end;
  int k = 0;
  scanf("%s",str);

  len = strlen(str);
  for(i = 0; i < len;i++){
    if(str[i] != '*'){
      start = i;
      break;
    }
  }
  for(i = len-1; i >= 0;i--){
    if(str[i] != '*'){
      end = i;
      break;
    }
  }

  //处理字符串
  for(i = 0; i < len; i++){
    if(i < start || i > end)
      result[k++] = str[i];
    else{
      if(str[i] != '*')
        result[k++] =str[i];
    }
  }

  printf("%s",result);
}
