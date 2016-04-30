//  The idea is as follows: 
//- replace each edge by two directed arcs 
//- find the shortest 1-N path (using Dijkstra or Bellman-Ford), remember its cost COST1 
//- replace the cost for all its arcs by INFINITY (you may not use them again) 
//- negate the cost for all their twin arcs (i.e. the arcs along the path in the opposite direction) 
//- find the shortest 1-N path (using Bellman-Ford, as now there are edges with negative cost), remember its cost COST2 
//- return COST1 + COST2 
//
//  Idea of the proof: 
//- The adjusted graph contains no negative cycles, because the first selected path was the shortest one. 
//- When searching for the second path, using an edge from the first path in an opposite direction corresponds to deleting this 
//  edge from the final solution. 
//    This is similar to finding an augmenting path in network flow algorithms.

#include <bits/stdc++.h>
using namespace std;
#define M 205
struct graph
{
	int a,b,wt;
	graph(int aa,int bb,int w):a(aa),b(bb),wt(w)
	{}
	graph()
	{}
};

void swap(graph& x,graph& y)
{
	swap(x.a , y.a);
	swap(x.b , y.b);
	swap(x.wt , y.wt);	
}
vector<graph> g;
	
int srch(int u,int v)
{
	for(int i=0;i<g.size();i++)
	{
		if(g[i].a == u and g[i].b == v)
			return i;
	}	
}

int main()
{
    int t,a,b,n,e,i,j,wt;
    int dis[M];
    int parent[M];
    int ans = 0;
    int u;
    
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);

    while(cin>>n)
	{
		if(n==0)		break;
		cin>>e;
		int k = 0;
		for(i=0;i<e;i++)
		{
			cin>>a>>b>>wt;
	        g.push_back(graph(a,b,wt));
	        g.push_back(graph(b,a,wt));
		}
		e = g.size();
        for (i = 0; i < n; ++i)
        {
            dis[i] = INT_MAX; 
        }
        dis[0] = 0;
        parent[0] = -1;
		for (i = 1; i < n; ++i)
        {
            for (j = 0; j < e; ++j)
            {
            	a = g[j].a;		b = g[j].b;		wt = g[j].wt;
            	if(dis[a] != INT_MAX and dis[b] > dis[a] + wt)
                {
                    dis[b] = dis[a] + wt;
                    parent[b] = a;
                }
            }
        }
        if(dis[n-1] == INT_MAX)
        {	cout<<"Back to jail\n";		}
        ans = dis[n-1];
		cout<<ans<<endl;
		for(int v=n-1 ; v!=0 ; v=parent[v])
    	{
    		u = parent[v];
    		g.erase(g.begin() + srch(u,v));
    		g[srch(v,u)].wt = -1*g[srch(v,u)].wt;
    	}
    	for (i = 0; i < n; ++i)
        {
            dis[i] = INT_MAX; 
        }
        dis[0] = 0;
        for (i = 1; i < n; ++i)
        {
            for (j = 0; j < e; ++j)
            {
            	a = g[j].a;		b = g[j].b;		wt = g[j].wt;
            	if(dis[a] != INT_MAX and dis[b] > dis[a] + wt)
                {
                    dis[b] = dis[a] + wt;
                    parent[b] = a;
                }
            }
        }
        if(dis[n-1] == INT_MAX)
        {	cout<<"Back to jail\n";		}
        ans += dis[n-1];
		cout<<ans<<endl;
		g.clear();
    }
}
