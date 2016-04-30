// 	getting total number of different groups in union find  ( got by different root and then using set )

#include<bits/stdc++.h>
#define M 50005
using namespace std;
int s[M];
int find(int x)
{
	if(s[x]<0)	
		return x;
//	else
//		return s[x] = find(s[x]);
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
void dounion(int a,int b)
{
	a = find(a);
	b = find(b);
	if(s[a]>=s[b])
	{
		s[b] += s[a];
		s[a] = b;
	}
	else
	{
		s[a] += s[b];
		s[b] = a;
	}
}
void show()
{
//	int num=s.size();
	for(int i=0;i<=10;i++)	
	    cout<<i<<"-> "<<s[i]<<endl;
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int n,m,a,b;
	set<int> st;
	for(int j=1;1;j++)
	{
		cin>>n>>m;
		memset(&s,-1,sizeof(s));
		if(n==0 && m==0)	break;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			if(find(a) != find(b))
				dounion(a,b);
		}
		for(int i=1;i<=n;i++)
		{
			//cout<<find(i)<<endl;
			st.insert(find(i));
		}
		cout<<"Case "<<j<<": "<<st.size()<<endl;
		st.clear();
	}
}
