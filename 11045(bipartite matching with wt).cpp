//	this que is of max bip. matching but lower layer has some wt to the sink which is given here at line 80-81

#include <bits/stdc++.h>
using namespace std;
#define M 200

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
	int shrt,men;
	string a,b;
	int t;
	map<string,int> mp;
	mp["XXL"] = 1;	mp["XL"] = 2;	mp["L"] = 3;	
	mp["M"] = 4;    mp["S"] = 5;	mp["XS"] = 6;
	cin>>t;
	while(t--)
	{
		memset(&g,0,sizeof(g));
		cin>>shrt>>men;
		for(int i=1;i<=men;i++)
		{
			cin>>a>>b;
			g[i][mp[a] + men] = 1;
			g[i][mp[b] + men] = 1;
		}
		for(int i=1;i<=men;i++)				//	source '0' to first layer linking
			g[0][i] = 1;
		for(int i=1;i<=6;i++)				//	second layer to sink linking
			g[men+i][men+6+1] = shrt/6;
		
		n = men+8;
	//	cout<<getmaxflow(0,men+7)<<endl;
		
		if(getmaxflow(0,men+7) == men)
			cout<<"YES";
		else	
			cout<<"NO";
		cout<<endl;
	}	
}
