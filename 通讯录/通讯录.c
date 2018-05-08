#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
struct person{
	char name[20];
	char sex[10];
	int age;
	char num[20];
	char e_mail[30];
};
#include "del_change.c"
#include "show_all.c"
#include "new.c"
#include "find.c" 
int menu(){
	int i,p;
	char bk	[50]="***********************************************";
	printf("\n%s\n\n",bk);
	char gn[][20]={"显示全部","查询/删除","新建","退出系统"};
	for(i=0;i<4;i++)
		printf("%d:%-14s\t",i+1,gn[i]);
	printf("\n\n");
	printf("%s\n%s",bk,"输入对应序号来使用功能:");
	scanf("%d",&p);
	return p;
}
int main(){
	int p;
	while(1){
		p=menu();
		switch(p){
			case 1: show_all();break;
			case 2: find();break;
			case 3: add();break;
			case 4: printf("\n谢谢您的使用!\n");exit(0);
			default: printf("请输入正确的指令序号:"); 
		}
	}
}
