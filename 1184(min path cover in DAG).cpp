//	for min path cover read page no - 87 - 88
//    "to split a DAG into paths" means "to leave at most one incoming and one outcoming edge for each vertex".
//	If we add an edge to the answer, we merge two paths into one.
//	Maximum matching algorithm tries to take as many edges as possible, while not violating the rule of one incoming and 
//	one outcoming edge. so after getting mbm when we subtract it from 

#include <bits/stdc++.h>
#define M 1000
using namespace std;
int in[M],out[M];

int g[M][M];
int parent[M];
bool visit[M];
int N;							
bool bfs(int s,int t)
{
	int v, tmp;
	memset(&visit,0,sizeof(visit));
	memset(&parent,-1,sizeof(parent));
	queue<int> q;
	q.push(s);		visit[s] = 1;		parent[s] = -1;
	while(!q.empty())
	{
		tmp = q.front();		q.pop();
		if(tmp == t)			return 1;
		for(int i=0;i<N;i++)
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
	int t,n,e,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>e;
		memset(&out,0,sizeof(out));
		memset(&in,0,sizeof(in));
		for(int i=0;i<n+n+2;i++)
		{
			for(int j=0;j<n+n+2;j++)
				g[i][j] = 0;
		}
		
		for(int i=0;i<e;i++)
		{
			cin>>a>>b;
			g[a][b+n] = 1;
			out[a]++;	in[b]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(out[i]>0)
				g[0][i] = 1;
			if(in[i]>0)
				g[i+n][n+n+1] = 1;
		}
		N = n+n+2;
		// for(int i=0;i<N;i++)
		// {
		// 	for(int j=0;j<N;j++)
		// 		cout<<g[i][j]<<" ";
		// 	cout<<endl;
		// }
		cout<<n-getmaxflow(0,N-1)<<endl;
	}
}
