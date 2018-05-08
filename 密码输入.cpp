#include <stdio.h> 
void main(void) 
{ 
	int i,a; 
	char b[20];; 
	i=0;
	printf("请输入密码:\t");
	while((a=getch())!='\r') {
		b[i++]=a; 
		printf("*"); 
	} 
	b[i]='\0';
	printf("\n输入完毕\n"); 
	printf("密码是: %s\n",b);
	getchar(); 
} 
