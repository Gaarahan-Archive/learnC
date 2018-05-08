#include<stdio.h>
#include<malloc.h>
#define MAX 20

typedef struct Node{
    int data;
    struct Node *Lchild;
    struct Node *Rchild;
}node,*bit_tree_node;

typedef struct {
    bit_tree_node data[MAX];
    int top;
}SeqStack;

void creat_tree(bit_tree_node *root);
void PrintTree(bit_tree_node root,int h);
SeqStack *Init_SeqStack();
void PreOrder(bit_tree_node root);
void InOrder(bit_tree_node root);
int IsEmpty(SeqStack *s);
int Push(SeqStack *s,bit_tree_node p);
int pop(SeqStack *s, bit_tree_node *p);

int main(){
    bit_tree_node root;
    int h = 1;
    creat_tree(&root);	//1 2 4 0 7 0 0 0 3 5 0 8 0 0 6 0 0
    PrintTree(root,h);
	printf("PreOrder :\n\t");
    PreOrder(root);
	printf("\nInOrder :\n\t");
	InOrder(root);
}
int IsEmpty(SeqStack *s){
    if(s->top == -1) return 1;
    else  return 0;
}
int Push(SeqStack *s,bit_tree_node p){
    if(s->top==MAX-1) return 0;
    else{
        s->top++;
        s->data[s->top] = p;
        return 1;
    }
}
int pop(SeqStack *s,bit_tree_node *p){
    if(IsEmpty(s)) return 0;
    else
    {
        *p = s->data[s->top];
        s->top--;
        return 1;
    }
}

void PreOrder(bit_tree_node root){
    SeqStack *S;
    bit_tree_node p;
    //modify 1 初始化为无参函数,S做返回值 
    S=Init_SeqStack();
    p = root;
    while(p!=NULL||!IsEmpty(S)){
        while(p!=NULL){
        // modify 2 去掉作用未知的visit,改为输出遍历到的结点 
        printf("%d ", p->data);
        Push(S,p);
        p = p->Lchild; 
    }
        if(!IsEmpty(S)){
            pop(S,&p);
            p = p->Rchild;
        }
	}
}

void InOrder(bit_tree_node root){ 
	SeqStack *S;
	bit_tree_node p;
	p=root;
	S=Init_SeqStack();
	while(p || !IsEmpty(S)){
		while(p){
			Push(S,p);
			p=p->Lchild;
		}
		if(!IsEmpty(S)){
			pop(S,&p);
     	   	printf("%d ", p->data);
			p=p->Rchild;
		}
	}
} 

SeqStack *Init_SeqStack(){
    SeqStack *s;
    s = malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

void PrintTree(bit_tree_node root,int h){
	int i;
	if(root == NULL) return;
	PrintTree(root->Rchild,h+1);
	for(i = 0; i < h; i++)
	    printf("     ");
    printf("%d\n",root->data);
	PrintTree(root->Lchild,h+1);
}

void creat_tree(bit_tree_node *root){
    int num;
    scanf("%d",&num);
    if(num ==  0){
		*root = NULL;
        }
    else{
        *root = (bit_tree_node)malloc(sizeof(node));
        (*root)->data = num;
        creat_tree(&(*root)->Lchild);
        creat_tree(&(*root)->Rchild);
    }
}

