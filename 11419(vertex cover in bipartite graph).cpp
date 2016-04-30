//   Good question on Min vertex cover of bipartite graph by konig's theorem we know that maximum matching in bg. is equal to
//	 min vertex cover of that bg.

#include <bits/stdc++.h>
using namespace std;
#define M 1005
int g[M][M];
int parent[M];
bool visit[M];
int N;							//	Number of vertices in graph
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

void showgraph()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<g[i][j];
		cout<<endl;
	}
}

void dfs(int u)
{
	for(int i=0;i<N;i++)
	{
		if(g[u][i]>0 and !visit[i])
		{
			visit[i] = 1;
			dfs(i);
		}
	}
}
int main()
{
	int r,c,e;
	int a,b;
	while(scanf("%d %d %d",&r,&c,&e) == 3)
	{
		if(r==0 and c==0 and e==0)		break;
		memset(&g,0,sizeof(g));
		
		for(int i=1;i<=r;i++)
			g[0][i] = 1;			//	adding source to each row (first layer)
		
		for(int i=1;i<=c;i++)
			g[r+i][r+c+1] = 1;		//	adding columns to sink (second layer)
		
		for(int i=1;i<=e;i++)
		{
			scanf("%d %d",&a,&b);
			g[a][b+r] = 1;			//	adding mid edges i.e. if point is at a,b   edge will be in between ath row and bth column
		}
		
		N = r+c+2;
	//	showgraph();
		printf("%d",getmaxflow(0,N-1));		//	here max_flow is equal to min vertex cover
	//	showgraph();
		
		memset(&visit,0,sizeof(visit));
		visit[0] = 1;
		dfs(0);
		
		//	below two lines are crucial got from residual graph, by which we are getting actual vertices which are in min cover		
		for(int i = 1;i<=r;++i) 	if(!visit[i]) printf(" r%d",i);
        for(int i = 1;i<=c;++i) 	if(visit[r+i]) printf(" c%d",i);
        printf("\n");
	}
}
