#include <stdio.h>
#include <malloc.h>
//每个节点只存放每个人的编号,出列后通过编号访问数组a[],读出其密码 

struct man{
	int num;
	struct man* next;
};

int main(){
	int i,n,password,sum,t;
	int *a;
	struct man* p;
	struct man* q;
	struct man* temp;//存放第一个结点的地址 
	struct man* p1;//指向出列者 
	struct man* p2;//指向出列者的前一人 
	
	//存储每个人的密码到数组a[] 
	printf("请输入人数n:");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("请输入每个人的密码:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("请输入初始密码:");
	scanf("%d",&password);
	
	
	//为每个人申请结点,并赋予编号 
	temp=p=malloc(sizeof(struct man));
	p->num=1;
	for(i=2;i<=n;i++){
		q=malloc(sizeof(struct man));
		q->num=i;
		p->next=q;
		p=q;
	}
	q->next=temp;

	printf("--ID--  --PASSWORD--\n");
	for(i=0;i<n;i++){
		printf("  %d        %d\n",i+1,a[i]);
	}

	//sum统计人数,每一次循环完毕sum减一,sum为一时停止循环 
	p1=p2=temp;
	sum=n;
	while(sum!=1){
		for(i=1;i<password;i++){
			p2=p1;
			p1=p1->next;
		}
		printf("第%d个人出列 <密码:%d>\n",p1->num,a[p1->num-1]);
		//找到出列者后将其删除,更新密码及p1的指向 
		t=p1->num;
		p1=p2->next=p1->next;
		password=a[t-1];
		sum--;
		
	}
	
	printf("最后剩下%d号,密码是%d",p2->num,a[p2->num-1]);

}
