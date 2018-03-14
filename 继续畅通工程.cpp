#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct edge{
int a,b,w,v;
	bool friend operator <(struct edge a,struct edge b)
	{
		return a.w>b.w;
	}
} e,temp[11000];
int main()
{
	int n;
	int flag=1;
	int ans=0;
	int cnt;
	priority_queue<struct edge,vector<struct edge>,less<struct edge> > g;
	set<int> x,y;
	while(scanf("%d",&n)!=-1)
	{
		ans=0;
		while(!g.empty())
			g.pop();
		x.clear();
		y.clear();
		if(n==1)
		{
			cin>>e.a>>e.b>>e.w>>e.v;
			cout<<"0"<<endl;
			continue;
		}
		if(n==0)
		{
			break;
		}
		
		for(int i=0;i<n;i++)
		{
			y.insert(i+1);
		}
		for(int i=0;i<n*(n-1)/2;i++)
		{
			cin>>e.a>>e.b>>e.w>>e.v;
			if(e.v)
			{
				e.w=0;
			}
			g.push(e);
		}
		e=g.top();
		g.pop();
		x.insert(e.a);
		x.insert(e.b);
		ans+=e.w;
		y.erase(y.find(e.a));
		y.erase(y.find(e.b));
		while(x.size()==n)
		{
			flag=1;
			cnt=0;
			e=g.top();
			while(flag)
			{
				if(((x.find(e.a)!=x.end())&&(x.find(e.b)==x.end())))
				{
					ans+=e.w;
					x.insert(e.b);
					y.erase(y.find(e.b));
					g.pop();
					flag=0;
				}
				else if((x.find(e.a)==x.end())&&(x.find(e.b)!=x.end()))
				{
					ans+=e.w;
					x.insert(e.a);
					y.erase(y.find(e.a));
					g.pop();
					flag=0;
				}
				else if(x.find(e.a)!=x.end()&&x.find(e.b)!=x.end())
					g.pop();
				else
				{
					g.pop();
					temp[cnt].a=e.a;
					temp[cnt].b=e.b;
					temp[cnt].w=e.w;
					cnt++;
				}
			}
			for(int i=0;i<cnt;i++)
			{
				g.push(temp[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}