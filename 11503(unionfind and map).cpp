#include<bits/stdc++.h>
#define M 100010
using namespace std;

int s[M];
int find(int x)					// 	non-recursive
{								
	if(s[x]<0)					// 	for recursive in else - return s[x] = find(s[x])
		return x;
	int y = x;
	for( ; s[y]>0; y=s[y]);
	int z = y;
	for( ; x!=z ; x=y)
	{
		y = s[x];	
		s[x] = z;
	}
	return z;		
}
void dounion( int root1,int root2)
{
	root1 = find(root1);
	root2 = find(root2);
	if(s[root1]>=s[root2])
	{
		s[root2]+=s[root1];
		s[root1]=root2;
	}
	else
	{
		s[root1]+=s[root2];
		s[root2]=root1;
	}
}
int main()
{
	int t,a,b,n,k;
	cin>>t;
	string str1,str2;
	map<string,int> mp;
	while(t--)
	{
		cin>>n;
		memset(&s,-1,sizeof(s));
		k = 0;
		for(int i=0;i<n;i++)
		{
			cin>>str1>>str2;
			if(mp.find(str1) == mp.end())
				mp[str1] = k++;
			if(mp.find(str2) == mp.end())
				mp[str2] = k++;
			a = mp[str1];		b = mp[str2];
			if(find(a) != find(b))
				dounion(a,b);
				
			cout<<-s[find(a)]<<endl;
		}
		mp.clear();
	}
}
