#include<stdio.h>
#include<malloc.h>
#define MAXNUM 50

//走过的路不能走
 
struct Seqstack{
	int direct[MAXNUM];
	int top; 
};

struct pos{
	int x;
	int y;
};

int push(int x,struct Seqstack* s){
	if(s->top==MAXNUM-1) return 0;
	s->direct[++s->top]=x;
	return 1;
}

int pop(struct Seqstack* s){
	int x;
	if(s->top==-1)return 0;
	x=s->direct[s->top--];
 	return x;
}

int dong(int x,int y){

	if(x<0||x>7||y<0||y>7)	return 1;
	return 0;
	
}

int search(int x,int* p,int num){
	int i;
	for(i=0;i<num;i++){
		if(p[i]==x)	return 1;
	}
	return 0;
}

struct pos* ahead(struct pos* p,int d){

	switch(d){
		case 1:p->x=p->x-2;p->y=p->y+1;break;
		case 2:p->x=p->x-1;p->y=p->y+2;break;
		case 3:p->x=p->x+1;p->y=p->y+2;break;
		case 4:p->x=p->x+2;p->y=p->y+1;break;
		case 5:p->x=p->x-2;p->y=p->y-1;break;
		case 6:p->x=p->x-1;p->y=p->y-2;break;
		case 7:p->x=p->x+1;p->y=p->y-2;break;
		case 8:p->x=p->x+2;p->y=p->y-1;break;
	}
	return p;
}

struct pos* back(struct pos* p,int d){

	switch(d){
		case 1:p->x=p->x+2;p->y=p->y-1;break;
		case 2:p->x=p->x+1;p->y=p->y-2;break;
		case 3:p->x=p->x-1;p->y=p->y-2;break;
		case 4:p->x=p->x-2;p->y=p->y-1;break;
		case 5:p->x=p->x+2;p->y=p->y+1;break;
		case 6:p->x=p->x+1;p->y=p->y+2;break;
		case 7:p->x=p->x-1;p->y=p->y+2;break;
		case 8:p->x=p->x-2;p->y=p->y+1;break;
	}
	return p;
}

int main(){
	int count=1;
	int d=1;
	int i;
	
	struct Seqstack* q;
	q=(struct Seqstack*)malloc(sizeof(struct Seqstack));
	if(q==NULL)printf("failed!");
	q->top=-1;
	
	struct pos *seat;
	seat=(struct pos*)malloc(sizeof(struct pos));
	seat->x=2;
	seat->y=3;
	while(count!=49){
		while(d<8){
			//不回头
			if(d+q->direct[q->top]==9){
				d++;
				continue;
			} 	
			seat=ahead(seat,d);
			if(dong(seat->x,seat->y)){
				back(seat,d);
				d++;
				}
			else {
				push(d,q);
				
				printf("%d    ",d);
				d=1;
				count++;
				
			}
		}
		if(d==8){
			
			d=pop(q); 
			back(seat,d);
			printf("b   \n");
			count--;
			d++;		
		}
	}
	for(i=0;i<=q->top;i++)
		printf("%d ",q->direct[i]);
}
