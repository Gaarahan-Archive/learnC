#include<stdio.h>
#include<malloc.h>

#define MAX 20

int visitedA[6]={0};
int visitedB[6]={0};

typedef struct
{
	int arcs[6][6]; 	//边 
	char vex[6];	//顶点 
	int vexnum;		//顶点数 
	int arcnum;		//边数 
} adjmatrix;

typedef struct{
	int data[MAX];
	int rear,front;
}Queue;

int Empty(Queue q){
	int num=q.rear-q.front;
	if(num==0)	return 1;
	return 0;
}

int EnterQueue(Queue *q,int x){
	int num=q->rear-q->front;
	if(num==MAX){
		printf("Queue full !");
		return -1;
	}

	else{
		q->rear++;
		q->data[q->rear]=x;
	}
}

int DeleteQueue(Queue *q,int *x){
	int num=q->rear-q->front;
        if(num==0){
		printf("Queue empty !");
		return -1;
	}
	else{
		q->front--;
		*x=q->data[q->front];
	}

}
//查找字符c 
int Locate(adjmatrix *G,char c)
{
	int k;
	for(k=0;k<G->vexnum;k++)
	if(G->vex[k]==c)
		return k;
	return -1; 
}

//建图 
void create(adjmatrix *G)
{
	int i,j,k;
	char vex1,vex2;
	printf("请输入结点个数和边数:");
	scanf("%d%d",&G->vexnum,&G->arcnum);
	printf("结点个数%d边数%d\n",G->vexnum,G->arcnum);
    
    //modify 1
    getchar();
	for(i=0;i<G->vexnum;i++){
	//  	G->vex[i]=getchar(); =
		scanf("%c",&G -> vex[i] );
	}
	
	for(i=0;i<G->vexnum;i++)
		printf("%d : %c\n",i,G->vex[i]);
		 
	//初始化边  
	for(i=0;i<G->vexnum;i++)
		for(j=0;j<G->vexnum;j++){
			G->arcs[i][j]=0;	
		}

	for(i=0;i<G->vexnum;i++){ 
		for(j=0;j<G->vexnum;j++)
		{
	    	printf("%d",G->arcs[i][j]);
		}
		printf("\n");
	}

	printf("输入边:\n");
	for(k=0;k<G->arcnum;k++)
    {
    //	printf("shuru:\n");
	    getchar();
		scanf(" %c%c",&vex1,&vex2);
	//	printf("权值:"); 
	//	scanf("%d",&weight);
	    printf("vex1:%c vex2:%c",vex1,vex2); 
		i=Locate(G,vex1);
		j=Locate(G,vex2);
		printf("sss");
		printf("%d %d\n",i,j);
		G->arcs[i][j]=1;
	//	G->arcs[j][i]=1;
	}
	
	for(i=0;i<G->vexnum;i++)
	{ 
		for(j=0;j<G->vexnum;j++)
		{
	    printf("%d",G->arcs[i][j]);
		}
		printf("\n"); 
	} 
}


int chudu(adjmatrix *G,char n)
{
	 int i,j,k=0;
	 for(i=0;i<G->vexnum;i++)
	 {
	 	if(n==G->vex[i])
	    break;
     }
 	 for(j=0;j<G->vexnum;j++)
 	 {
 	 	if(G->arcs[i][j]==1) 
 	 	{
 	      k++;
 	 	}
     }
   printf(" %d",k);
   
}

int rudu(adjmatrix *G,char n)
{  
     int i,j,k=0;
	 for(i=0;i<G->vexnum;i++)
	 {
	 	if(n==G->vex[i])
	    break;
     }
 	 for(j=0;j<G->vexnum;j++)
 	 {
 	 	if(G->arcs[j][i]==1) 
 	 	{
 	      k++;
 	 	}
     }
	 printf("%d ",k);
}


int FirstAdjVex(adjmatrix *G,int v0){
	int i;
	for(i=0;i<G->vexnum;i++){
		if(G->arcs[v0][i]==1)
			return i;
	}
	
	return -1;
}

int NextAdjVex(adjmatrix *G,int v0,int w){
	int i;
	for(i=w+1;i<G->vexnum;i++){
		if(G->arcs[v0][i]==1)
			return i;
	}
	
	return -1;
}

//深度优先遍历：从v0开始遍历图G
void DFS(adjmatrix *G,int v0){
	int w;
	printf("%c",G->vex[v0]);
	visitedA[v0]=1;
	w=FirstAdjVex(G,v0);
	
	while(w!=-1){
		if( !visitedA[w] )	DFS(G,w); //对与未被遍历的结点，进行遍历
		w=NextAdjVex(G,v0,w);
	}
}

//借助栈将递归转化为非递归
/*
void DFSWithoutRecursion(adjmatrix *G,int v0){
	InitStack(S);
	int visitedA[MAX] = {0};
	Push(S,v0);
	while( !Empty(S) ){ 
		v=Pop(S);			
		if(!visitedA[v]){			//对于栈内每个未被访问结点v进行访问
			printf("%c",G->vex[v]);
			visitedA[w] = 1;
		}

		//遍历v的所有邻结点，将还未被访问的结点入栈
		w=FirstAdjVex(G,v);		
		while(w!=-1){
			if( !visitedA[w] ) Push(S,w);
			w=NextAdjVex(G,v,w);
		}
	}

}
*/

void BFS(adjmatrix *G,int v0){
	int w;
	Queue Q;
	printf("%c",G->vex[v0]);
	visitedB[v0]=1;
	EnterQueue(&Q,v0);
	while (! Empty(Q)){
		DeleteQueue(&Q,&v0);
		w=FirstAdjVex(G,v0);
		while(w!=-1){
			if(!visitedB[w]){
				printf("%c",G->vex[0]);
				visitedB[w]=1;
				EnterQueue(&Q,w);
			}
			w=NextAdjVex(G,v0,w);
		}
	}
}

int main()
{   
	int i;
   	char n;
   	adjmatrix G;
   	int chu,ru;
 	create(&G);
  	printf("出度:\n");
   	for(i=0;i<G.vexnum;i++){
		printf("\n%c ",G.vex[i]);
		chudu(&G,G.vex[i]);
	  	rudu(&G,G.vex[i]);
	}
	
	printf("深度: \n"); 
   	DFS(&G,0);
   	
   	printf("广度: \n");
	BFS(&G,0);   
	
}
   
 

