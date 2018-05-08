/*************************************************************************
> File Name: Test1.c
> Author: QRM
> Mail: 
> Created Time: 2017年11月02日 星期四 20时29分14秒
 ************************************************************************/

#include<stdio.h>

#include <stdlib.h>

#define MAXSIZE 200

/* 定义二叉树节点类型 */
typedef struct node
{
    int  data;
    struct node *lchild, *rchild;
}BTNode;

/* 函数声明 */
BTNode* CreatBitTree();
void PreOrder(BTNode*);
void InOrder(BTNode*);
void PostOrder(BTNode*);
//PrintTree(BTNode *root,int h);
/* 主函数 */
int main()
{
    BTNode *root = NULL;
    int h = 5;
    root = CreatBitTree();
    PreOrder(root);
    InOrder(root);
    PostOrder(root);
  //  PrintTree(root,h);
    return 0;
}
/*打印*/
//void PrintTree(BTNode * root,int h){
//	if(root == NULL) return;
//	PrintTree(root->rchild,h+1);
//	for(int i = 0; i < h; i++)
//	    printf("     ");
  //  printf("%d\n",root->data);
//	PrintTree(root->lchild,h+1);
//}
/* 递归前序建立二叉树 */
BTNode* CreatBitTree()
{
    int ch;
    BTNode *b;
    //fflush(stdin);
    scanf("%d",&ch);
    /* 遇到空节点停止递归 */
    if (ch == 0)
    {
        b = NULL;
    }
    else
    {
        b = (BTNode*) malloc(sizeof(BTNode));
        /* 建立根节点 */
        b->data = ch;
        /* 递归先序建立左子树 */
        b->lchild = CreatBitTree();
        /* 递归先序建立右子树 */
        b->rchild = CreatBitTree();
    }
    return b;
}

/* 非递归先序遍历二叉树 */
void PreOrder(BTNode* b)
{
    BTNode *stack[MAXSIZE], *p;
    int top = -1;
    if (b != NULL)
    {
        /* 根节点入栈 */
        top++;
        stack[top] = b;
        /* 栈不空时循环 */
        while (top > -1)
        {
            /* 出栈并访问该节点 */
            p = stack[top];
            top--;
            printf("%d ", p->data);
            /* 右孩子入栈 */
            if (p->rchild != NULL)
            {
                top++;
                stack[top] = p->rchild;
            }
            /* 左孩子入栈 */
            if (p->lchild != NULL)
            {
                top++;
                stack[top] = p->lchild;
            }
        }
        printf("\n");
    }
}

/* 非递归中序遍历二叉树 */
void InOrder(BTNode* b)
{
    BTNode *stack[MAXSIZE], *p;
    int top = -1;
    if (b != NULL)
    {
        p = b;
        while (top > -1 || p != NULL)
        {
            /* 扫描p的所有左节点并入栈 */
            while (p != NULL)
            {
                top++;
                stack[top] = p;
                p = p->lchild;
            }
            if (top > -1)
            {
                /* 出栈并访问该节点 */
                p = stack[top];
                top--;
                printf("%d ", p->data);
                /* 扫描p的右孩子 */
                p = p->rchild;
            }
        }
        printf("\n");
    }
}

/* 非递归后序遍历二叉树 */
void PostOrder(BTNode* b)
{
    BTNode *stack[MAXSIZE], *p;
    int sign, top = -1;
    if (b != NULL)
    {
        do
        {
            /* b所有左节点入栈 */
            while (b != NULL)
            {
                top++;
                stack[top] = b;
                b = b->lchild;
            }
            /* p指向栈顶前一个已访问节点 */
            p = NULL;
            /* 置b为已访问 */
            sign = 1;
            while (top != -1 && sign)
            {
                /* 取出栈顶节点 */
                b = stack[top];
                /* 右孩子不存在或右孩子已访问则访问b */
                if (b->rchild == p)
                {
                    printf("%d ", b->data);
                    top--;
                    /* p指向被访问的节点 */
                    p = b;
                }
                else
                {
                    /* b指向右孩子节点 */
                    b = b->rchild;
                    /* 置未访问标记 */
                    sign = 0;
                }
            }
        }while (top != -1);
        printf("\n");
    }
}
