//	reference Cp1 - pageno - 88-91  read carefully !!
//	here we need to get max weight independent set so for that purpose we are connecting those vertices which are conflicting
//	and then we are getting max flow (i.e. reverse) then we will subtract it from total weight.


#include <bits/stdc++.h>
using namespace std;
#define M 100
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
char buffer[1000];
int main()
{
	int t,n1,n2,wt,a,b,k,total,xtra;
	string str;
	cin>>t;
	map<int,int> mp;
	for(int cas = 1;cas<=t;cas++)
	{
		total = 0;
		xtra = 0;
		memset(&visit,0,sizeof(visit));
		memset(&g,0,sizeof(g));
		cin>>n1;
		for (int i = 1 ; i <= n1 ; ++i) 
		{
			 scanf("%d",&wt);
			 total += wt;
			 g[0][i] = wt;					//	source to Layer a
			 cin.getline(buffer,1000);
			 char * p = strtok(buffer," ");
			 while (p)
			 {
				 sscanf(p,"%d",&a);
				 mp[a] = i;
				 p = strtok(NULL," ");
		     }
	 	}
		scanf("%d*c",&n2);
	 	for (int i = 1 ; i <= n2 ; ++i) 
	 	{
		 	scanf("%d",&wt);
		 	total += wt;
		 	g[i+n1][n1+n2+1] = wt;			//	Layer b to sink
		 	cin.getline(buffer,1000);
			char * p = strtok(buffer," ");
		 	while (p) 
		 	{
			 sscanf(p,"%d",&b);
			 if(mp.count(b) == 1)
			 {
			 	visit[mp[b]] = 1;
			 	g[mp[b]][i+n1] = INT_MAX;
		 	 }
			 p = strtok(NULL," ");
		 	}
	 	 } 
		N = n1+n2+2;
		/*
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
		k = getmaxflow(0,N-1);
		printf("Case %d:\n",cas);
		cout<<total - k<<endl;
		cout<<endl;
		mp.clear();
	}	
}
