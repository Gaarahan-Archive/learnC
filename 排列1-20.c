#include <stdio.h>

int X[21],used[21];//X[]Ϊ������ uesd[]��¼�Ƿ��ù�

int count=0; //����

//��ʼ����� 
void Init(){
	int i;
	for(i=0;i<21;i++){
		X[i]=used[i]=0;
 	}
}


int IsisPrime(int k)//�ж��Ƿ�������,�Ƿ��� 1,���򷵻� 0 
{
	int i;
 for(i=2;i<=k/2;i++)
 {
  if(!(k%i))return 0;
 }
 return 1;
}

//�ж�i�ܷ���,kΪ������,��¼�Ѿ���������ָ��� 
int xianjie(int k,int i){

	if(k==1)return 1;//��һ���� 
	
	int sum=X[k-1]+i;//sumΪ�жϵ�i����������λ�õ�������ĺ� 
	
	if(!IsisPrime(sum))return 0;//�Ͳ�������
	
	if(k==20){
		sum+=X[1]+i;//���һ����,�������һ�������ν� ,�޸���k 
		if(!IsisPrime(sum))return 0;
	}
	
 	if(used[i])return 0;//��ʹ�ò������� 
 	
 	return 1;
}


void Output()
{
	int i;
 	count++;
 	printf("%d ������\n",count);
 	for(i=1;i<=20;i++){
		printf("-->%d",X[i]);
	}
 	printf("\n");
}


void fun(int k)
{
	int i;
	if(k==21)Output();//�Ѿ���20��������Ҫ��
	else{
		for(i=1;i<=20;i++)
   		if(xianjie(k,i)){
   			X[k]=i;
   			used[i]=1;
   			fun(k+1);
   			used[i]=0;//��˷
  		}
 	}
}
 
int main(){
	Init();
	fun(1); 
	return 0;
}
