#include<stdio.h>
#include <conio.h>
void main(void)
{
int color;
for (color = 0; color < 8; color++){ 
��textbackground(color); /*�����ı��ı�����ɫ*/
��cprintf("This is color %d\r\n", color);
��cprintf("ress any key to continue\r\n");
��getch(); /*�����ַ�������*/
��}
}
