#include<stdio.h>
#include<malloc.h>

struct Poly{
	float coef;
	int expn;
	struct Poly* next;
};

struct Poly* creat(){
	float c;
	int e;
	struct Poly *head,*p,*q;
	head=p=q=malloc(sizeof(struct Poly));
	printf("输入系数及次数（系数为0表示结束）：");
	scanf("%f%d",&c,&e);
	while(c!=0){
		
		q=malloc(sizeof(struct Poly));
		q->coef=c;
		q->expn=e;
		p->next=q;
		printf("输入系数及次数（系数为0表示结束）：");
		scanf("%f%d",&c,&e);
		p=q;
	}
	p->next=NULL;
	return head;
}

void print(struct Poly* x){
	struct Poly *p;
	p=x->next;
	if(x->next==NULL){
		printf("多项式为空");
		return ;
	}
	printf("%.0fX^%d",p->coef,p->expn);
	p=p->next;
	while(p){
		if(p->coef==0)p=p->next;
		printf("+%.0fX^%d",p->coef,p->expn);
		p=p->next;
	}
	printf("\n");
}

struct Poly* add(struct Poly* a,struct Poly* b){
	
	struct Poly *c,*p,*q;
	p=c=q=malloc(sizeof(struct Poly));
	while(a&&b){
		p=q;
		if(a->expn>b->expn){
			p->coef=b->coef;
			p->expn=b->expn;
			b=b->next;
		}
		else if(a->expn<b->expn){
			p->coef=a->coef;
			p->expn=a->expn;
			a=a->next;
		}
		else{
			p->coef=a->coef+b->coef;
			p->expn=a->expn+b->expn;
			a=a->next;
			b=b->next;
		}
		q=malloc(sizeof(struct Poly));
		p->next=q;
	}
	while(a){
		p=q;
		q->coef=a->coef;
		q->expn=a->expn;
		a=a->next;
		q=malloc(sizeof(struct Poly));
		p->next=q;
	}
	while(b){
		p=q;
		q->coef=b->coef;
		q->expn=b->expn;
		b=b->next;
		q=malloc(sizeof(struct Poly));
		p->next=q;
	}
	p->next=NULL;
	
	return c;
}

//a-b=a+(-b)
struct Poly* subtract(struct Poly* a,struct Poly* b){
	struct Poly* c;
	while(b->next){
		b->coef=-b->coef;
		b=b->next;
	}
	c=add(a,b);
	return c;
}
/*乘法,未完成 
struct Poly* multiply(struct Poly* a,struct Poly* b){
	struct Poly* c;
	struct Poly* s;
	struct Poly* temp,*p,*q;
	s=b;
	temp=p=q=malloc(sizeof(struct Poly));
	while(s->next){
		p=q;
		q=malloc(sizeof(struct Poly));
		s=s->next;
		p->next=q;
	}
	p->next=NULL;
	q=temp;
	for(a;a->next;a=a->next){
		//将temp中的值存为 
		while(s->next){
				q->coef=s->coef;
				q->expn=s->expn;
			s=s->next;
			q=q->next;
		}
		for(b;b->next;b=b->next){
			
		}
	}
}*/

int main(){
	char ch;
	struct Poly *pa,*pb,*pc;
	printf("the first:\n");
	pa=creat();
	printf("the second:\n");
	pb=creat();
	
	
	printf("the first:\n");
	print(pa);
	printf("the second:\n");
	print(pb);
	
	getchar();
	printf("请输入运算符(+或-):");
	scanf("%c",&ch);
	if(ch=='+')pc=add(pa,pb);
	if(ch=='-')pc=subtract(pa,pb);
	printf("the sum：\n");
	print(pc);
}

