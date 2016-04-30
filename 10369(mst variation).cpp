#include<bits/stdc++.h>
#include<list>
#include<queue>
#include<vector>
#define sqr(x)  ((x)*(x))
using namespace std;
typedef pair<int,int> ii;
int s[502];

int find(int x)
{
	if(s[x]<0)
		return x;
	else
		return s[x]=find (s[x]);
}
void dounion( int root1,int root2)
{
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
vector<ii> v;
vector< pair< int,ii > > ans,e;
int dis(int i,int j)
{
	return sqr(v[i].first - v[j].first)  +  sqr(v[i].second - v[j].second) ;
}
int main()
{
	int t,sete,n,a,b;
	ii p;
	cin>>t;
	while(t--)
	{
		cin>>sete>>n;
		memset(&s,-1,sizeof(s));
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			v.push_back(ii(a,b));
		}
		if(sete >= n)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				e.push_back(make_pair(  dis(i,j) , ii(i,j) ));
			}
		}
		sort(e.begin(),e.end());
		for(int i=0;i<e.size();i++)
		{
			if(ans.size() == n-1)		break;
			p = e[i].second;
			a = p.first;	b = p.second;
			a =  find(a);	b = find(b);
			if(a!=b)
			{
				dounion(a,b);
				ans.push_back(e[i]);
			}
		}
		
	//	for(int i=0;i<ans.size();i++)
	//		cout<<ans[i].second.first<<"  "<<ans[i].second.second<<"  "<<ans[i].first<<endl;
			
		printf("%.2f\n",sqrt(ans[ans.size() - sete].first));
		ans.clear();
		v.clear();
		e.clear();
	}
}
