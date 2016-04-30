#include<bits/stdc++.h>
using namespace std;
#define M 505
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
int n;
vector<int> topo;
int dis[M];
int cas = 1;
int in[M];

void topological(vvi& g , int s)
{
	int u,v;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		u = q.front();		q.pop();
		topo.push_back(u);
		for(int i=0;i<g[u].size();i++)
		{
			v = g[u][i];
			if(--in[v] == 0)
				q.push(v);
		}
	}
}

void longest_path(vvi& g)
{
	int u,v;
	memset(&dis,0,sizeof(dis));
	
	for(int i=0 ; i<n ; i++)
	{
		u = topo[i];
	//	cout<<u<<endl;
		for(int j=0;j<g[u].size();j++)
		{
			v = g[u][j];
			if(dis[v] < dis[u] + 1)
				dis[v] = dis[u] + 1;
		}
	}
	int maxv = 0 , fst;
	for(int i=0 ; i<n ; i++)
	{
	//	cout<<i<<"  "<<dis[i]<<endl;
		maxv = max(maxv , dis[i]);
	}
	for(int i=0 ; i<n ; i++)
	{
		if(dis[i] == maxv)
		{
			fst = i;
			break;
		}
	}
	printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",cas,topo[0]+1,maxv,fst+1);
}
int main()
{
	int s,a,b;
	while(cin>>n and n)
	{
		cin>>s;
		vvi g(n+1);
		s--;
		memset(&in,0,sizeof(in));
		while(cin>>a>>b)
		{
			if(a==0 and b==0)	break;
			a--;	b--;
			g[a].push_back(b);
			in[b]++;
		}
		topological(g,s);
		longest_path(g);
		g.clear();
		topo.clear();
		cas++;
	}
}
