#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
int primesize;
int prime[100001];
int mark[100001]={0};
void init()
{
    primesize=0;
    for(int i=2;i<=100000;i++)
    {
        if(mark[i]==1) continue;
        prime[primesize++]=i;
        if(i>=1000) break;
        for(int j=i*i;j<=100000;j+=i)
            mark[j]=1;
    }
}
int main()
{
    int n;
    init();
	int ans;
    while(scanf("%d",&n)!=EOF)
    {
		int ansprime[30];
        int anssize=0;
		int ansnum[30]={0};
        for(int i=0;i<primesize;i++)
        {
            if(n%prime[i]==0)
            ansprime[anssize]=prime[i];
            while(n%prime[i]==0)
            {
                ansnum[anssize]++;
                n/=prime[i];
            }
            anssize++;
            if(n==1) break;
        }
        if(n!=1)
        {
            ansprime[anssize]=n;
            ansnum[anssize++]=1;
        }
		ans=0;
        for(int i=0;i<anssize;i++)
        {
            ans+=ansnum[i];
        }
        printf("%d",ans);
    }
    return 0;
}