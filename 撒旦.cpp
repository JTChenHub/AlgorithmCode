#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct BTNode
{
	BTNode *lchild;
	BTNode *rchild;
	char c;
}Tree[210];
char str[110];
int loc=0;
int i;
char x;
BTNode *build()
{
	
	x=str[i++];
	if(x=='#') return NULL;
	BTNode *t=new BTNode;
	t->c=x;
	t->lchild=build();
	t->rchild=build();
	return t;
}
void inorder(BTNode *t)
{
	if(t->lchild) inorder(t->lchild);
	printf("%c ",t->c);
	if(t->rchild) inorder(t->lchild);
}
int main()
{
	while(scanf_s("%s",str,110)!=EOF)
	{
		i=0;
		BTNode*b=NULL;
		b=build();
		inorder(b);
	}
	return 0;
}
