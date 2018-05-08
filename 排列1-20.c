#include <stdio.h>

int X[21],used[21];//X[]为解向量 uesd[]记录是否被用过

int count=0; //计数

//初始化标记 
void Init(){
	int i;
	for(i=0;i<21;i++){
		X[i]=used[i]=0;
 	}
}


int IsisPrime(int k)//判断是否是素数,是返回 1,否则返回 0 
{
	int i;
 for(i=2;i<=k/2;i++)
 {
  if(!(k%i))return 0;
 }
 return 1;
}

//判断i能否被用,k为计数器,记录已经存入的数字个数 
int xianjie(int k,int i){

	if(k==1)return 1;//第一个数 
	
	int sum=X[k-1]+i;//sum为判断的i与其欲存入位置的左端数的和 
	
	if(!IsisPrime(sum))return 0;//和不是素数
	
	if(k==20){
		sum+=X[1]+i;//最后一个数,考虑与第一个数的衔接 ,修改了k 
		if(!IsisPrime(sum))return 0;
	}
	
 	if(used[i])return 0;//被使用不能再用 
 	
 	return 1;
}


void Output()
{
	int i;
 	count++;
 	printf("%d 方案：\n",count);
 	for(i=1;i<=20;i++){
		printf("-->%d",X[i]);
	}
 	printf("\n");
}


void fun(int k)
{
	int i;
	if(k==21)Output();//已经有20个数满足要求
	else{
		for(i=1;i<=20;i++)
   		if(xianjie(k,i)){
   			X[k]=i;
   			used[i]=1;
   			fun(k+1);
   			used[i]=0;//回朔
  		}
 	}
}
 
int main(){
	Init();
	fun(1); 
	return 0;
}
