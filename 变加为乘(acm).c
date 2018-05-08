#include<stdio.h>
#include<stdlib.h>
int main(){
	int X,Y,n,i,j=0,k,count,flag;
	scanf("%d",&n);
	int a[n][2];
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	for(i=0;i<n;i++){
		if(i!=0)printf("\n");
		X=a[i][0];
		Y=a[i][1];
		count=0;
		flag=-1;
		j=0; 
		while(count<=X){
			j++;
			count+=j;
			if(count==X)break;
		}
		if(count>X)	flag=0;
		
		count=j;
		for(j=0;j<count&&flag!=0;j++){
			for(k=j+2;k<count;k++){
				if((X-2*j-2*k-2+j*(j+1)+k*(k+1))==Y){ 
					printf("(%d,%d)",j,k);
					flag=1; 
				} 
			} 
		}
		if(flag==0||flag==-1)printf("NONE");

	}
}
