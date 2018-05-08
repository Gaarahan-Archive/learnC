#include<stdio.h>
int main(){
	int i,sum=0,j=0;
	char a[100];
	int num[100];
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='0'&&a[i]<='9'){
			num[j++]=a[i]-48;
		}
	}
	sum=num[0]; 
	printf("%d",num[0]);
	for(i=1;i<j;i++){
		printf("+%d",num[i]);
		sum+=num[i];
	}
	printf("=%d",sum);
}
