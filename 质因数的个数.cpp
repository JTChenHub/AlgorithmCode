#include<iostream>
using namespace std;
int p[100000];
void init()
{
	int flag=1;
	int k=0;
	for(int i=2;i<200000;i++)
	{
		flag=1;
		for(int j=2;j*j<=i;j++)
			if(i%j==0) 
			{
				flag=0;
				break;
			}
		if(flag==1) 
		{
			p[k]=i;
			k++;
		}


	}
}
int main()
{
	int n;
	int i=0;
	int k=0;
	int ans;
	init();
	while(cin>>n)
	{
		i=2;
		ans=0;
		while(n!=1)
		{
			if(n%i==0)
			{
				n=n/i;
				ans++;
			}
			else
			{
				if(p[k]!=0)
					i=p[k++];
				else
					i++;
			}
		}
		cout<<ans;
	}
	return 0;
}