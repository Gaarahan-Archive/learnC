#include<stdio.h>
int main(){
	char a[]="a";
	char b[]="b";
	if(rename(a,b)==0)printf("!!");
}
