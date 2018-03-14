#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long  m(long long a,long long b)
{
	long long c=a;
	while(b)
	{
		if(b%2==0)
		{
		a*=a;
		b/=2;
		}
		else
		{
			a*=c;
			b--;
		}
	}
	return a;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
		long long d,p;
		long long k;
		long long a[3];
		long long x;
		for(int i=0;i<3;i++)
		{
			scanf("%lld",&a[i]);
		}
		scanf("%lld",&k);
		if((a[2]-a[1])==(a[1]-a[0]))
		{
			d=a[2]-a[1];
			x=a[0]+(k-1)*d;
		}
		else if((a[2]/a[1])==(a[1]/a[0]))
		{
			p=a[2]/a[1];
			x=a[0]*m(p,k-2);
		}
			printf("%lld\n",x);
		}
	}
	return 0;
}