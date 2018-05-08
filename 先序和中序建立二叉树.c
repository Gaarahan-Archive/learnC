#include <stdlib.h>  
#include<stdio.h>  
#include <string.h>  
  
#define  N  100  
  
typedef struct BiTNode    
{    
    char data;    
    struct BiTNode *lchild,*rchild;    
} BiTNode,* BITree;    
  
//先序遍历    
void preOrder(BiTNode*root)    
{    
    if (root==NULL)    
    {    
        return;    
    }    
    printf("%c ",root->data);    
    preOrder(root->lchild);    
    preOrder(root->rchild);    
}    
//中序遍历    
void inOrder(BiTNode*root)    
{    
    if (root==NULL)    
    {    
        return;    
    }    
    inOrder(root->lchild);    
    printf("%c ",root->data);    
    inOrder(root->rchild);    
}

BiTNode* createBiTree(char *pre, char *in, int n)  
{  
    int i = 0;  
    int n1 = 0,n2 = 0;  
    int m1 = 0,m2 = 0;  
    BiTNode*node = NULL;  
    char lpre[N],rpre[N];  
    char lin[N],rin[N];  
    if (n == 0)  
    {  
        return NULL;  
    }  
    node = (BiTNode*)malloc(sizeof(BiTNode));    
    if (node==NULL)    
    {    
        return NULL;    
    }    
    memset(node,0,sizeof(BiTNode));   
    //先序序列的第一个元素必为根结点  
    node->data = pre[0];  
    //根据根结点将中序序列分为左子树和右子数  
    for (i = 0;i<n;i++)  
    {  
        if ((i<=n1)&&(in[i]!=pre[0]))  
        {  
            lin[n1++] = in[i];  
        }  
        else if(in[i]!=pre[0])  
        {  
            rin[n2++] = in[i];  
        }  
    }  
    //根据树的先序序列的长度等于中序序列的长度  
    //且先序遍历是先左子树再后子树,无论先序还是中序 左子树和右子树的长度都是固定的  
    //主意 从i=1开始 因为先序遍历的第一个是根   
    for (i = 1;i < n;i++)  
    {  
        if (i< (n1+1))//n1代表了左子树的长度  
        {  
            lpre[m1++] = pre[i];  
        }  
        else  
        {  
            rpre[m2++] = pre[i];  
        }  
    }  
    node->lchild = createBiTree(lpre,lin,n1);  
    node->rchild = createBiTree(rpre,rin,n2);  
  
    return node;  
}  

void PrintTree(BITree root,int h){
	int i;
	if(root == NULL) return;
	PrintTree(root->rchild,h+1);
	for(i = 0; i < h; i++)
	    printf("     ");
    printf("%c\n",root->data);
	PrintTree(root->lchild,h+1);
}

int main()  
{  
    char preNode[N];  
    char inNode[N];  
    int n = 0;  
    char ch;  
    BiTNode* root=NULL;  
    printf("请输入先序序列\n");			//ABDHKECFIGJ  
    while((ch = getchar())&&ch!='\n')  
        preNode[n++] = ch;  
    printf("请输入中序序列\n");  		//HKDBEAIFCGJ
    n = 0;  
    while((ch = getchar())&&ch!='\n')  
        inNode[n++] = ch;  
    root = createBiTree(preNode,inNode,n);  
  
  	PrintTree(root,1);

}  
