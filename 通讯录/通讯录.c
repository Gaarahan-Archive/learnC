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
	char gn[][20]={"��ʾȫ��","��ѯ/ɾ��","�½�","�˳�ϵͳ"};
	for(i=0;i<4;i++)
		printf("%d:%-14s\t",i+1,gn[i]);
	printf("\n\n");
	printf("%s\n%s",bk,"�����Ӧ�����ʹ�ù���:");
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
			case 4: printf("\nлл����ʹ��!\n");exit(0);
			default: printf("��������ȷ��ָ�����:"); 
		}
	}
}
