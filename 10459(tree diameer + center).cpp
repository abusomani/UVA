// In this question bfs is used at most 4(min 3) times.  first one from any vrtx to find a leaf.  then from that
// vrtx second bfs is done 'with parent information' in this(the longest one) path at half we will get the centre
// (if long path is even then 2 centre otherwise 1 center)  and then from these centre we are again doing bfs to get
// 'Max distant leaves'.

#include <bits/stdc++.h>
using namespace std;
#define M 5005
typedef vector<vector<int> > vvi;
int n;
int dis[M];
bool visit[M]; 
int parent[M];
vector<int> good,bad;
 
void bfs(vvi& g,int s,vector<int>& bad)
{
	int u,v;
	memset(&visit,0,sizeof(visit));
	memset(&dis,0,sizeof(dis));
	queue<int> q;
	int maxv = 0;
	q.push(s);
	dis[s] = 0;		visit[s] = 1;		
	while(!q.empty())
	{
		u = q.front();		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			v = g[u][i];
			if(!visit[v])
			{
				visit[v] = 1;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}	
	for(int i=0;i<n;i++)
	{
	//	cout<<i<<" && "<<dis[i]<<endl;
		maxv = max(maxv,dis[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(dis[i] == maxv)
			bad.push_back(i+1);
	}
}
int bfs(vvi& g,int s,bool on)
{
	int u,v;
	memset(&visit,0,sizeof(visit));
	memset(&dis,0,sizeof(dis));
	queue<int> q;
	int maxv = 0;
	q.push(s);
	dis[s] = 0;		visit[s] = 1;		parent[s] = -1;
	while(!q.empty())
	{
		u = q.front();		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			v = g[u][i];
			if(!visit[v])
			{
				visit[v] = 1;
				dis[v] = dis[u] + 1;
				parent[v] = u;
				q.push(v);
			}
		}
	}
	if(on)
	{
		for(int i=0;i<n;i++)
		{
		//	cout<<i<<" & "<<dis[i]<<endl;
			if(maxv < dis[i])
			{
				maxv = dis[i];
				s = i;
			}
		}
		bfs(g,s,0);	
	}
	else
	{
		for(int i=0;i<n;i++)
		{
		//	cout<<i<<" |& "<<dis[i]<<endl;
			if(maxv < dis[i])
			{
				maxv = dis[i];
				s = i;
			}
		}
		if(maxv%2 == 0)
		for(v = s; v!=-1 ; v=parent[v])
		{
			if(dis[v] == maxv/2)
				good.push_back(v+1);
		}
		else
		for(v = s; v!=-1 ; v=parent[v])
		{
			if(dis[v] == maxv/2 || dis[v] == maxv/2 + 1)
				good.push_back(v+1);
		}
		
		for(int i=0;i<good.size();i++)
			bfs(g,good[i]-1,bad);
		
		sort(good.begin() , good.end());
		sort(bad.begin() , bad.end());
		
		printf("Best Roots  :");
		for(int i=0;i<good.size();i++)
			cout<<" "<<good[i];
		cout<<endl;
		
		printf("Worst Roots :");
		for(int i=0;i<bad.size();i++)
			cout<<" "<<bad[i];
		cout<<endl;
		
		good.clear();
		bad.clear();
	}
}
int main()
{
	int k,a;
	while(cin>>n)
	{
		vvi g(n+1);
		for(int i=0;i<n;i++)
		{
			cin>>k;
			for(int j=0;j<k;j++)
			{
				cin>>a;
				a--;
				g[i].push_back(a);
				g[a].push_back(i);
			}
		}
		bfs(g,0,1);
		g.clear();
	}
}
