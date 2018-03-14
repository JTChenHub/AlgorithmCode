#include<iostream>
#include<algorithm>
using namespace std;
int f[10100];
int main()
{
	int n;
	int ans;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>f[i];
		}
		sort(f,f+n);
		if(n%2==0)
		{
			ans=(f[n/2]+f[n/2-1])/2;
		}
		else
			ans=f[n/2];
		cout<<ans<<endl;
	}
	
	return 0;
}