#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREAD 3 //线程的个数

unsigned long long main_counter,counter[MAX_THREAD];

void* thread_worker(void*);

int main(int agrc,char* argv[]){
  int i,rtn,ch;
  pthread_t pthread_id[MAX_THREAD] = {0};//存放线程的ID
  for(i = 0; i < MAX_THREAD; i++) {
    //填写代码,用pthread_create建立一个普通的线程，线程id存入
    //pthread_id[i],线程执行函数是thread_worker并i作为参数传递线程
    rtn = pthread_create(&pthread_id[i],NULL, thread_worker,(void*)i);

    if(rtn!=0){
      printf("Create pthread error!\n");
      return -1;
    }

  }
  do{
    //用户按一次回车执行下面的循环体一次。按q退出
    unsigned long long sum = 0;
    //求所有线程的counter的和
    for(i = 0; i < MAX_THREAD; i++){
      sum+=counter[i];
      printf("线程:%llu\t",counter[i]);
    }
    printf("%llu %llu",main_counter,sum);
  } while((ch=getchar())!='q');
  return 0;
}
void* thread_worker(void* p){
  int thread_num;
  //在这里写代码，把main中的i的值传递给thread_num
  thread_num =(int) p;
  for(;;){
    counter[thread_num]++;//本线程的counter加一
    main_counter++; //主counter加一
  }
}
