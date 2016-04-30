//		Bipartite matching

#include <bits/stdc++.h>
using namespace std;
#define M 500
#define sq(x) ((x)*(x))
struct paired
{
    double x,y;
};
int g[M][M];
int parent[M];
bool visit[M];
int N;					//	Number of vertices in graph
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
double dis(paired a,paired b)
{
	return sqrt( sq(a.x - b.x) + sq(a.y - b.y) );
}
int main()
{
    int n,m,s,v;
    paired rabit[M] , hole[M];
    double val;
	while(cin>>n>>m>>s>>v)
    {
        for (int i = 0; i < n; ++i)
        {
            cin>>rabit[i].x>>rabit[i].y;
        }
        for (int i = 0; i < m; ++i)
        {
            cin>>hole[i].x>>hole[i].y;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                val = dis(rabit[i] , hole[j]);
                if( val <= v*s )				//		if dis is less than the time than we include an edge in graph
                    g[i+1][j+n+1] = 1;
            }
        }
        memset(&g,0,sizeof(g));
        for(int i=1;i<=n;i++)	
        	g[0][i] = 1;
        for(int i=n+1;i<=m+n;i++)
        	g[i][m+n+1] = 1;
        /*
        for(int i=0;i<=m+n+1;i++)
        {
        	for(int j=0;j<=m+n+1;j++)
        	{
        		cout<<g[i][j]<<"  ";
        	}
        	cout<<endl;
        }*/
        N = m+n+2;
		cout<<n - getmaxflow(0,m+n+1)<<endl;
    }
}
