#include<bits/stdc++.h>
#define M 30010
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
	int n,m,maxi,t,a,b;
	cin>>t;
	while(t--)
	{
		memset(&s,-1,sizeof(s));
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			if(find(a)!=find(b))
				dounion(a,b);
		}
		maxi = 100000;
		for(int i=1;i<=n;i++)
		{
			maxi = min(maxi,s[i]);
		}
		cout<<-maxi<<endl;
	}
}
