#include <bits/stdc++.h>
using namespace std;
#define M 5005
typedef vector<vector<int> > vvi;
int n;
bool visit[M]; 
int parent[M];
int dis[M];
 
void bfs(vvi& g,int s,int t)
{
	int u,v,k=0;
	int x,y;
	memset(&visit,0,sizeof(visit));
	memset(&dis,0,sizeof(dis));
	queue<int> q;
	q.push(s);
	parent[s] = -1;		visit[s] = 1;		dis[s] = 0;		
	while(!q.empty())
	{
		u = q.front();		q.pop();
		if(u == t)			break;
		for(int i=0;i<g[u].size();i++)
		{
			v = g[u][i];
			if(!visit[v])
			{
				visit[v] = 1;
				parent[v] = u;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	if(dis[t]%2 == 0)
	{
		for(v = t; v!=-1 ; v=parent[v])
		{
			if(k == dis[t]/2)
				x = v;
			k++;	
		}
		printf("The fleas meet at %d.\n",x+1);
	}
	else
	{
		for(v = t; v!=-1 ; v=parent[v])
		{
			if(k == dis[t]/2)
				x = v;
			if(k == dis[t]/2 + 1)
				y = v;
			k++;
		}
		if(x>y)		swap(x,y);
		printf("The fleas jump forever between %d and %d.\n",x+1,y+1);
	}
}

int main()
{
	int a,b,l;
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	while(cin>>n and n)
	{
		vvi g(n+1);
		for(int i=0;i<n-1;i++)
		{
			cin>>a>>b;
			a--;	b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		cin>>l;
		for(int i=0;i<l;i++)
		{
			cin>>a>>b;
			a--;	b--;
			bfs(g,a,b);
		}
	}
}
