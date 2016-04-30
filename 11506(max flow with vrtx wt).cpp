#include <bits/stdc++.h>
#define M 200
using namespace std;
int g[M][M];
int parent[M];
bool visit[M];
int n;

void dfs(int u)
{
	visit[u] = 1;
	for(int i=0;i<n;i++)
	{
		if(g[u][i]>0 and !visit[i])
			dfs(i);		
	}
}
bool bfs(int s,int t)
{
	memset(&visit,0,sizeof(visit));
	//memset(&parent,-1,sizeof(parent));
	queue<int> q;
	int u;
	q.push(s);
	visit[s] = 1;		parent[s] = -1;
	while(!q.empty())
	{
		u = q.front();		q.pop();
		if(u == t)			return 1;
		for(int i=1;i<=n;i++)
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

int min_cut(int s,int t)
{
	int min_flow , max_flow = 0;
	int u,v;
	while(bfs(s,t))
	{
		min_flow = INT_MAX;
		for(v=t ; v!=s ; v=parent[v])
		{
			u = parent[v];
			min_flow = min(min_flow , g[u][v]);
		}
		for(v=t ; v!=s ; v=parent[v])
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
	int w,x,y;
	int a,b,wt,t;
	while(cin>>n>>w)
	{
		if(n==0 and w==0)		break;
		memset(&g,0,sizeof(g));
		for(int i=0;i<n-2;i++)
		{
			cin>>a>>wt;
			g[a][a+n-1] = wt;			//	vertex wt converting to edge wt
			g[a+n-1][a] = wt;
		}
		for(int i=0;i<w;i++)
		{
			cin>>a>>b>>wt;
			x = (a==1)?0:n-1;
			y = (b==n)?0:n-1;
			g[a + x][b] = wt;
			g[b + y][a] = wt;
		}
		t = n;
		n += n-2;
		cout<<min_cut(1,t)<<endl;
	}
}
