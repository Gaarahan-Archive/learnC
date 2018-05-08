#include<stdio.h>
#include<malloc.h>
#define MAXNUM 50

struct Seqstack{
	int direct[MAXNUM];
	int top; 
};

int wall[30]={13,17,21,23,25,27,35,36,38,42,43,44,45,47,54,62,66,68,72,73,74,75,78,81,82,84,86,88,91,92};

void print(void)
{
	printf("0 0 * 0 0 0 * 0\n");
	printf("* 0 * 0 * 0 * 0\n");
	printf("0 0 0 0 * * 0 *\n");
	printf("0 * * * * 0 * 0\n");
	printf("0 0 0 * 0 0 0 0\n");
	printf("0 * 0 0 0 * 0 *\n");
	printf("0 * * * * 0 0 *\n");
	printf("* * 0 * 0 * 0 *\n");
	printf("* * 0 0 0 0 0 0\n");
}


int push(int x,struct Seqstack* s){
	if(s->top==MAXNUM-1) return 0;
	s->direct[++s->top]=x;
	return 1;
}

int pop(struct Seqstack* s){
	int x;
	if(s->top==-1)return 0;
	x=s->direct[s->top--];
//返回出栈元素
 	return x;
}

int dong(int x,int y){
//做了修改,防止转圈 (21,25,45) 
//用一维数组存储墙的坐标,判断输入的坐标是否是墙的坐标(撞墙)
//用数字1 2 3 4分别代表上 右 左 下 
//撞墙返回 1;否则返回 0;  

	if(x<1||x>9||y<1||y>8)	return 1;
	
	int i;
	for(i=0;i<30;i++){
		if(x*10+y==wall[i]) return 1;
	}
	return 0;
}

//判断x是否在数组p中 
int search(int x,int* p,int num){
	int i;
	for(i=0;i<num;i++){
		if(p[i]==x)	return 1;
	}
	return 0;
}

int main(){
//预设(1,1)为入口,(9,8)为出口;初始方向为上 
	int x,y,x1,y1;
	int d,i,j,k;
	x=y=1;
	
	printf("迷宫:\n");
	print(); 
	//建立栈 
	struct Seqstack* q;
	q=malloc(sizeof(struct Seqstack));
	if(q==NULL)printf("failed!");
	q->top=-1;
	
	push(2,q);
	//停止条件 
	d=1;
	while(1){
	
		while(d<5){
			//不回头
			if(d+q->direct[q->top]==5){
				d++;
				continue;
			} 
			//坐标变化用x1,y1临时存储 
			x1=x;
			y1=y;
			switch(d){
				case 1:x1=x-1;break;
				case 2:y1=y+1;break;
				case 3:y1=y-1;break;
				case 4:x1=x+1;break;
			}
		//每次判断,撞墙则d自增,否则压入d,存储变化后的x,y 
			if(dong(x1,y1))	d++;
				
			else {
				push(d,q);
				x=x1;
				y=y1;
				d=1;
			}
		}
		
		if(x==9&&y==8)break;
		//三个方向都走不通,回头;退出栈顶元素,归位坐标
		if(d==5){
			
			d=pop(q); 
			switch(d){
				case 1:x=x+1;break;
				case 2:y=y-1;break;
				case 3:y=y+1;break;
				case 4:x=x-1;break;
			}
			d++;
		}
		
	}
	
	//输出结果
	printf("\n栈中数据:\n"); 
	for(i=0;i<=q->top;i++){
		printf("%d",q->direct[i]);
	}
	printf("\n");
	
	x=y=1;
	int road[30];
	road[0]=11;
	for(i=1;i<=q->top;i++){
		switch(q->direct[i]){
				case 1:x=x-1;break;
				case 2:y=y+1;break;
				case 3:y=y-1;break;
				case 4:x=x+1;break;
			}
		road[i]=x*10+y;
	}
	
	int flag=0;
	for(i=1;i<10;i++){
		for(j=1;j<9;j++){
			k=i*10+j;
			if(search(k,road,q->top+1))	printf("0 ");
			else if(search(k,wall,30))	printf("* ");
			else printf("  ");

		}
		printf("\n");
	}
}
