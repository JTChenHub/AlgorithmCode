#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
char s[100];
int main()
{
	string s1;
	while(gets(s))
	{
		s1=s;
		for(int i=0;i<s1.length();i++)
		{
			if((s1[i]<='Z'-1&&s1[i]>='A')||(s1[i]<='z'-1&&s1[i]>='a'))
				s1[i]++;
			else if(s1[i]=='Z')
				s[i]='A';
			else if(s1[i]=='z')
				s[i]='a';
		}
		cout<<s1<<endl;
	}
	return 0;
}