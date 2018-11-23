#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_CHILD_NUMBER 10
#define SLEEP_INTERVAL2
int proc_number=0;
void do_something();
int main(int argc,char* argv[]){
  int child_proc_number=MAX_CHILD_NUMBER;
  int i,ch;
  pid_t pid[10]={0};
  if(argc>1){
    child_proc_number=atoi(argv[1]);
    child_proc_number=(child_proc_number>10)?10:child_proc_number;
  }
  /*建立子进程*/
  for(i=0;i<child_proc_number;i++)
  {
    if((proc_number=fork())==0)
    {
      proc_number=i;
      do_something();
    }
    else
    {
      pid[i]=proc_number;
    }
  }
  while((ch=getchar())!='q')
  {
    if(isdigit(ch))
    {
      kill(pid[ch-'0'],SIGTERM);
    }
  }
  kill(0,SIGTERM);
  return 0;
}
void do_something()
{
  for(;;)
  {
    printf("This is process No.%d and its pid is %d\n",proc_number,getpid());
    sleep(2);
  }
}
