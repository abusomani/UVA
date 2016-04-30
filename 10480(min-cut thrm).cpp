//Following are steps to print all edges of minimum cut.
//1) Run Ford-Fulkerson algorithm and consider the final residual graph.
//2) Find the set of vertices that are reachable from source in the residual graph.
//3) All edges which are from a reachable vertex to non-reachable vertex are minimum cut edges. Print all such edges.

#include <bits/stdc++.h>
#define M 55
using namespace std;
int g[M][M];
int rg[M][M];
int parent[M];
bool visit[M];
int n;

bool bfs(int s,int t)
{
	int v,u;
	memset(&visit,0,sizeof(visit));
	memset(&parent,-1,sizeof(parent));
	queue<int> q;
	q.push(s);	
	visit[s] = 1;		
	while(!q.empty())
	{
		u = q.front();		q.pop();
		if(u == t)		return 1;
		for(int i=0;i<n;i++)
		{ 
			if(g[u][i]>0 and !visit[i])
			{
				visit[i] = 1;
				parent[i] = u;
				q.push(i);
			}  
		}
	}
	return 0;
} 
void dfs(int u)
{
	visit[u] = 1;
	for(int i=0;i<n;i++)
	{
		if(g[u][i]>0 and !visit[i])
		{
			dfs(i);
		}
	}
}
void min_cut(int s,int t)				//	same as edmond_karp except last few lines
{
	int u,v;
	int min_flow;
	int max_flow = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			rg[i][j] = g[i][j];
	}
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
	memset(&visit,0,sizeof(visit));
	dfs(s);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(visit[i] == 1 and visit[j] == 0 and ( rg[i][j]>0 ))
			{
				cout<<i+1<<" "<<j+1<<endl;
			}
		}
	}
}
int main()
{
	int e,a,b,wt;
	while(cin>>n>>e)
	{
		if(n==0 and e==0)		break;
		memset(&g,0,sizeof(g));
		for(int i=0;i<e;i++)
		{
			cin>>a>>b>>wt;
			a--;	b--;
			g[a][b] = wt;
			g[b][a] = wt;
		}
		min_cut(0,1);
		cout<<endl;
	}
}
