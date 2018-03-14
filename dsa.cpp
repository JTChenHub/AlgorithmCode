#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int judge(int x)
{
	if(x<=1) return 0;
	else
	{
		int bound=sqrt(x)+1;
		for(int i=2;i<=bound;i++)
		{
			if(x%bound==0) return 0;
	
		}
		return 1;
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans=judge(n);
		if(ans==1) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
