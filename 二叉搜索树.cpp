#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
struct BTNode
{
	BTNode *lchild;
	BTNode *rchild;
	int c;
}Tree[210]={0};
int loc;
BTNode *creat()
{
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
BTNode *Insert(BTNode *t,int x)
{
	if(!t)
	{
		t=creat();
		t->c=x;
	}
	else if(x<t->c) t->lchild=Insert(t->lchild,x);
	else if(x>t->c) t->rchild=Insert(t->rchild,x);
	return t;
}
int *size;
char *str;
char str1[25],str2[25];
int size1,size2;
void preorder(BTNode *t)
{
	str[(*size)++]=t->c+'0';
	if(t->lchild) preorder(t->lchild);
	if(t->rchild) preorder(t->rchild);

}
void inorder(BTNode *t)
{
	
	if(t->lchild) inorder(t->lchild);
	str[((*size)++)]=t->c+'0';
	if(t->rchild) inorder(t->rchild);

}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		char tmp[25];
		loc=0;
		scanf("%s",tmp);
		BTNode *B=NULL;
		for(int i=0;tmp[i]!=0;i++)
		{
			B=Insert(B,tmp[i]-'0');
		}
		size1=0;
		str=str1;
		size=&size1;
		preorder(B);
		inorder(B);
		str1[size1]=0;
		while(n--)
		{
			scanf("%s",tmp);
			BTNode *C=NULL;
		for(int i=0;tmp[i]!=0;i++)
		{
			C=Insert(C,tmp[i]-'0');
		}
		size2=0;
		str=str2;
		size=&size2;
		preorder(C);
		inorder(C);
		str2[size2]=0;

		puts(strcmp(str1,str2)==0?"YES":"NO");
		}
	}
	return 0;
}