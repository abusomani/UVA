/*
	for printing matches in a max bm  , check residual graph which is got after mbm , all entries which are '1' from 
	second layer to first layer(i.e. reversed edges) are selected matching so print them out. (done here in line - 120-130)
*/

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
void getmaxflow(int s,int t)					//	edmond - karp implementation
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
}
string str[M][M];
int p;
string sch(int i,int j)
{
	int ch;
	for(int m=0;m<p;m++)
	{
	//	cout<<str[i][m]<<endl;
		ch = (int)toupper(str[i][m][0]) - 'A' + 1;
		if(ch == j)
		{
			str[i][m][0] = toupper(str[i][m][0]);
			for(int k=1;k<str[i][m].length();k++)
				str[i][m][k] = tolower(str[i][m][k]);
			return str[i][m];
		}
	}
}
int main()
{
	int t,num,v;
	int cas = 1;
	cin>>t;
	while(t--)
	{
		cin>>p;
		memset(&g,0,sizeof(g));				//	this step is necessary for multicase
		for(int i=1;i<=p;i++)
		{
			cin>>num;
			for(int j=0;j<num;j++)
			{
				cin>>str[i][j];
				v = (int)toupper(str[i][j][0]) - 'A' + p + 1;
				g[i][v] = 1;
			}
		}
		for(int i=1;i<=p;i++)
			g[0][i] = 1;
		for(int i=1;i<=p;i++)
			g[p+i][p+26+1] = 1;
		
		N = p+28;
		
		for(int i=0;i<p+p+3;i++)
		{
			for(int j=0;j<N;j++)
				cout<<g[i][j]<<"";
			cout<<endl;
		}
		
		getmaxflow(0,N-1);
//		cout<<getmaxflow(0,N-1);
		
		for(int i=0;i<p+p+3;i++)
		{
			for(int j=0;j<N;j++)
				cout<<g[i][j]<<"";
			cout<<endl;
		}
		vector<string> ans;
		for(int i=1;i<=p;i++)
		{
			for(int j=1;j<=p;j++)
			{
				if(g[p+i][j] == 1)					//	checking reverse edges for final matched edges.
				{
//					cout<<p+i<<"  "<<j<<endl;	
					ans.push_back( sch(i,j) );
				}
			}
		}
		sort(ans.begin() , ans.end());
		printf("Case #%d:\n",cas++);
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<endl;
		ans.clear();
	}	
}
