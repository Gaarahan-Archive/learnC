#include <stdio.h>
#include <malloc.h>
//ÿ���ڵ�ֻ���ÿ���˵ı��,���к�ͨ����ŷ�������a[],���������� 

struct man{
	int num;
	struct man* next;
};

int main(){
	int i,n,password,sum,t;
	int *a;
	struct man* p;
	struct man* q;
	struct man* temp;//��ŵ�һ�����ĵ�ַ 
	struct man* p1;//ָ������� 
	struct man* p2;//ָ������ߵ�ǰһ�� 
	
	//�洢ÿ���˵����뵽����a[] 
	printf("����������n:");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("������ÿ���˵�����:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("�������ʼ����:");
	scanf("%d",&password);
	
	
	//Ϊÿ����������,�������� 
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

	//sumͳ������,ÿһ��ѭ�����sum��һ,sumΪһʱֹͣѭ�� 
	p1=p2=temp;
	sum=n;
	while(sum!=1){
		for(i=1;i<password;i++){
			p2=p1;
			p1=p1->next;
		}
		printf("��%d���˳��� <����:%d>\n",p1->num,a[p1->num-1]);
		//�ҵ������ߺ���ɾ��,�������뼰p1��ָ�� 
		t=p1->num;
		p1=p2->next=p1->next;
		password=a[t-1];
		sum--;
		
	}
	
	printf("���ʣ��%d��,������%d",p2->num,a[p2->num-1]);

}
