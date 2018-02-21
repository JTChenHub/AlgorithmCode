#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct BTNode
{
	BTNode *lchild;
	BTNode *rchild;
	int c;
}Tree[101];
int loc;
BTNode *creat()
{
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
BTNode *c(BTNode *t,int x)
{
	if(t==NULL)
	{
		t=creat();
		t->c=x;
	}
	
	else if(x<(t->c))  t->lchild=c(t->lchild,x);
	else if(x>(t->c))  t->rchild=c(t->rchild,x);
	return t;

}
void preorder(BTNode *t)
{
	printf("%d ",t->c);
	if(t->lchild) preorder(t->lchild);
	if(t->rchild) preorder(t->rchild);
}
void inorder(BTNode *t)
{
	if(t->lchild) inorder(t->lchild);
	printf("%d ",t->c);
	if(t->rchild) inorder(t->rchild);
}
void postorder(BTNode *t)
{
	if(t->lchild) postorder(t->lchild);
	if(t->rchild) postorder(t->rchild);
	printf("%d ",t->c);
}
int main()
{
	int n;
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		int a[100];
		loc=0;
		BTNode *T=NULL;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			T=c(T,a[i]);
		}
		preorder(T);
		printf("\n");
		inorder(T);
		printf("\n");
		postorder(T);
		printf("\n");
	}
	return 0;
}