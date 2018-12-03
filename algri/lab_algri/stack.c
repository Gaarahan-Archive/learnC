/*输入一串字符,找出字符中匹配括号()的数目*/
#include<malloc.h>
#include<stdio.h>
#include<string.h>

typedef struct{
	char chset[50];
	int top;
}stack;

stack* init(){
	stack *s = (stack*)malloc(sizeof(stack));
	s->top = 0;
}

int push(stack *s,char ch){
	if(s->top == 49){
		return 0;
	}
	s->chset[s->top++] = ch;
	return 1;
}

int pop(stack* s){
	if(s->top == 0){
		return 0;
	}
	s->top--;
	return 1;
}

int main(){
	stack* s = init();
	char str[50];
	scanf("%s",str);

	int i;
	int flag,count=0;
	int len = strlen(str);
	for(i = 0; i < len;i++){
		flag = 0;
		if(str[i] == '('){
			push(s,'(');
		}
		else if(str[i] == ')'){
			flag = pop(s);
			if(flag == 1)
				count ++;
		}
	}
	printf("%d",count);
}

