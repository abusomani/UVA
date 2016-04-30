//	Uva 820
//	Straight problem on edmond karp max flow algorithm

#include <bits/stdc++.h>
#define M 105
using namespace std;
int g[M][M];
int parent[M];
bool visit[M];
int n;					//	Number of vertices in graph
bool bfs(int s,int t)
{
	int v, tmp;
	memset(&visit,0,sizeof(visit));
	queue<int> q;
	q.push(s);		visit[s] = 1;		parent[s] = -1;
	while(!q.empty())
	{
		tmp = q.front();		q.pop();
		if(tmp == t)			return 1;
		for(int i=0;i<n;i++)
		{
			v = i;
			if(g[tmp][i]>0 and !visit[v])
			{
				visit[v] = 1;
				parent[v] = tmp;
				q.push(v);	
			}
		}
	}
	return 0;
}
int getmaxflow(int s,int t)					//	edmond - karp implementation
{
	int u,v;
	int min_flow;
	int max_flow = 0;
	while(bfs(s,t))
	{
		min_flow = INT_MAX;
		for(int v=t ; v!=s ; v=parent[v])
		{
			u = parent[v];
			min_flow = min(min_flow , g[u][v]);
		}
		
		for(int v=t ; v!=s ; v=parent[v])
		{
			u = parent[v];
			g[u][v] -= min_flow;
			g[v][u] += min_flow;
		}
		
		max_flow += min_flow;
	}
	return max_flow;
}
int main()
{
	int s,t,e,a,b,wt;
	int cas = 0;
	while(cin>>n and n)
	{
		cas++;
		cin>>s>>t>>e;
		s--;	t--;
		memset(&g,0,sizeof(g));
		for(int i=0;i<e;i++)
		{
			cin>>a>>b>>wt;
			a--;	b--;
			g[a][b] = wt;
			g[b][a] = wt;
		}
		printf("Network %d\nThe bandwidth is %d.\n",cas,getmaxflow(s,t));
	}
}
