#include <stdio.h> 
void main(void) 
{ 
	int i,a; 
	char b[20];; 
	i=0;
	printf("����������:\t");
	while((a=getch())!='\r') {
		b[i++]=a; 
		printf("*"); 
	} 
	b[i]='\0';
	printf("\n�������\n"); 
	printf("������: %s\n",b);
	getchar(); 
} 
