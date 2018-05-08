#include<stdio.h>
#include<stdlib.h>
struct per {
	char num[10];
	char name[8];
	char sex;
	int age;
	struct per *next;
};
void input(struct per *x){
	scanf("%s%s",x->num,x->name);
	getchar();
	scanf("%c%d",&x->sex,&x->age);
}
void print(struct per *x){
	printf("num:%s\nname:%s\nsex:%c\nage:%d\n\n",x->num,x->name,x->sex,x->age);
}
int main(){
	int i,n;
	struct per *head=NULL,*p=NULL,*q=NULL,*x,a;
	head=malloc(sizeof(struct per));
	if(head==NULL) {printf("worng!");exit(0);}
	input(head);
	p=head;
	for(i=1;i<5;i++){
		q=malloc(sizeof(struct per));
		if(q==NULL) {printf("worng!");exit(0);}
		input(q);
		p->next=q;
		p=q;
	}
	p->next=NULL;
	printf("输入要插入的前一个元素年龄:);
	scanf("%d",&n);
	printf("输入要插入的信息:");
	input(&a); 
	x=head;
	while(x!=NULL){
		if(x->age==n){ 
			print(x);
			a.next=x->next;
			x->next=&a; 
		} 
		x=x->next;
	}
	printf("插入完成!\n");
	x=head;
	while(x!=NULL){
		print(x);
		x=x->next;
	}
}

