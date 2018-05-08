#include<stdio.h>

int jiec(int x){
	int i;
	int result = 1;
	for(i = 0; i < x;i++){
		result *= i;
	}
	return result;
}


int zuhe(int n,int i){
	return jiec(n)/(jiec(i)*jiec(n-i));
}

int jump(int n){
	int now = 0,i = 0;
	int max = n/2;
	int min = 0;

	for(i = min; i < max;i++){
		now += zuhe(n-i,i);
	}
}

int main(){
	int n = 0;
	int s;
	scanf("%d",&n);
	printf("%d",n);
	s = jump(n);
	printf("%d    ",s);
}
