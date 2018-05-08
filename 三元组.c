#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000

typedef struct{
	int row,col,value;
}Triple; 
typedef struct{
	Triple data[MAXSIZE+1];
	int rows,cols,nums;
}TSMatrix;

void getMatrix(TSMatrix *x){
	int i=0;
	x->nums=0;
	printf("input the row and col and nums:");
	scanf("%d%d%d",&x->rows,&x->cols,&x->nums);
	while(x->rows>20||x->rows<0||x->cols<0||x->cols>20||x->nums<0){
		printf("wrong input!\n");
		printf("input the row(0<row<=20) and col(0<col<=20) and nums(num>0):");
		scanf("%d%d%d",&x->rows,&x->cols,&x->nums);
	}
	printf("input the Matrix by row (row col value): \n");
	for(i=0;i<x->nums;i++){
		scanf("%d%d%d",&x->data[i].row,&x->data[i].col,&x->data[i].value);
	}
}

void print(TSMatrix *x){
	int i,j,k,set,count,flag;//set 表示位置 ，count 表示已处理元素个数 ,flag表示是否有元素输出 
	for(i=1;i<=x->rows;i++){
		for(j=1;j<=x->cols;j++){
			flag=0;
			for(k=0;k<x->nums;k++){
				if(i==x->data[k].row&&j==x->data[k].col){
					printf("%4d",x->data[k].value);
					flag=1; 
					break;
				}
			}
			if(flag==0)	printf("%4d",0);
		}
		printf("\n");
	}
}
//加法
TSMatrix* add(TSMatrix* a,TSMatrix* b){
	TSMatrix *c=malloc(sizeof(TSMatrix));
	int i=0,j=0,k=0;
	while(i<a->nums&&j<b->nums){
		if((a->data[i].row*10+a->data[i].col) == (b->data[j].row*10+b->data[j].col)){
			c->data[k].row=a->data[i].row;
			c->data[k].col=a->data[i].col;
			c->data[k++].value=a->data[i].value+b->data[j].value;
			i++;
			j++;
		}
		else if((a->data[i].row*10+a->data[i].col) < (b->data[j].row*10+b->data[j].col)){
			c->data[k].row=a->data[i].row;
			c->data[k].col=a->data[i].col;
			c->data[k++].value=a->data[i].value;
			i++;
		}
		else {
			c->data[k].row=b->data[j].row;
			c->data[k].col=b->data[j].col;
			c->data[k++].value=b->data[j].value;
			j++;
		}
	}
	for(i;i<a->nums;i++){
		c->data[k].row=a->data[i].row;
		c->data[k].col=a->data[i].col;
		c->data[k++].value=a->data[i].value;
	}
	for(j=j;j<b->nums;j++){
		c->data[k].row=b->data[j].row;
		c->data[k].col=b->data[j].col;
		c->data[k++].value=a->data[j].value;
	}
	
	c->rows=a->rows;
	c->cols=a->cols;
	c->nums=k;
}

//减法 返回a-b 
TSMatrix* minus(TSMatrix* a,TSMatrix* b){
	int i;
	TSMatrix* c;
	TSMatrix* d;
	//copy b to x
	d->cols=b->cols;
	d->nums=b->nums;
	d->rows=b->rows;
	for(i=0;i<b->nums;i++){
		d->data[i].value=-b->data[i].value;
		d->data[i].col=b->data[i].col;
		d->data[i].row=b->data[i].row;
	}
	c=add(a,d);
	return c; 
} 
//相乘
int  
 
int main(){
	TSMatrix *m1=malloc(sizeof(TSMatrix));
	TSMatrix *m2=malloc(sizeof(TSMatrix));
	TSMatrix *m3;
	printf("input Matrix 1:\n");
	getMatrix(m1);//1 2 14 1 5 -5 2 2 -7 3 1 36 3 4 28
	print(m1);
	printf("input Matrix 2:\n");
	getMatrix(m2);//1 2 2 1 3 5 3 5 1
	print(m2);
	m3=add(m1,m2);
	printf("add result :\n");
	print(m3);
	m3=minus(m1,m2);
	
}

