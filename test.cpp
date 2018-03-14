#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int num[1000]={0};
int maxeven(int start, int end)
{
	int a,b;
    if(start==end)
    {
        if(num[start]%2==0)
			return num[start];
        else 
			return -1;
    }
    else
    {
        a=maxeven(start,(end+start)/2);
		if((end+start)/2+1<=end)
			b=maxeven((end+start)/2+1,end);
		else 
			b=-1;
        if(a>b)return a;
        if(a<b)return b;
        if(a==b&&a==-1) return -1;
        if(a==b) return a;
    }
    
}
int main()
{
	int n,i;
	i=0;
//	cin>>n;
	for(int i=0;i<19;i++)
	{
		num[19-i-1]=i;;
		cout<<num[19-i-1];
	}
	n=20;
	i=maxeven(0,n-1);
	cout<<i;
	return 0;
}
