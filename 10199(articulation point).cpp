#include<bits/stdc++.h>
#define M 100
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vi artipt;
int low[M];
bool visit[M];
int parent[M];
int disc[M];

void showgraph(vvi& g)
{
	for(int i=0;i<g.size();i++)
	{
		cout<<(i+1)<<"  : ";
		for(int j=0;j<g[i].size();j++)
			cout<<g[i][j]+1<<"  ";
		cout<<endl;
	}
}
int times = 0;
void modified_dfs(vvi& g,int u)					// assuming graph is connected
{
	visit[u] = 1;		disc[u] = low[u] = times++;
	cout<<u+1<<" ";	
	int v;
	int child = 0;	
	for(int i=0;i<g[u].size();i++)
	{	
		v = g[u][i];
		if(!visit[v])
		{
			child++;
			parent[v] = u;
			modified_dfs(g,v);
			if(disc[u] <= low[v] and parent[u] != -1)							//  Articulation point checuing
			{
				artipt.push_back(u);
			}
			if(parent[u] == -1 and child>1)
			{
				artipt.push_back(u);
			}
//			if(u<low[v])								//  Bridge condition
//				bridge.push_back(ii(u,v));		
				
			low[u] = min(low[u],low[v]);				//  comparing with child's low
			
		}	
		else if(v != parent[u])
		{
			low[u] = min(low[u],disc[v]);				//  comparing with ancestor's num
		}
	}
}
/*
int r=0;
void dfs(vvi& v,int k)
{
	visit[k] = 1;	disc[k] = low[k] = r++;
	int child = 0;
	for(int i=0;i<v[k].size();i++)
	{
		if(!visit[v[k][i]])
		{
			child++;
			parent[v[k][i]] = k;
			dfs(v,v[k][i]);
			if(disc[k] <= low[v[k][i]] and parent[k] != -1)
			{
				artipt.push_back(k);
			}
			if(parent[k] == -1 and child>1)
			{
				artipt.push_back(k);
			}
			low[k] = min(low[k],low[v[k][i]]);
			
		}
		else if(v[k][i] != parent[k])
		{
			low[k] = min(low[k],disc[v[k][i]]);
		}
	}
}*/
void get_apoint(vvi& v)
{
	times = 0;
	memset(&parent,-1,sizeof(parent));
	memset(&visit,0,sizeof(visit));
	modified_dfs(v,0);
}

int main()
{
	int n,e;
	int j = 0;
	map<string,int> mp;
	string str[M],str1,str2;
	while(1)
	{
		j++;	
		cin>>n;	
		if(!n)		break;
		vvi v(n);
		for(int i=0;i<n;i++)
		{
			cin>>str[i];
			mp[str[i]] = i;
		}
		cin>>e;
		for(int i=0;i<e;i++)
		{
			cin>>str1>>str2;
			v[mp[str1]].push_back(mp[str2]);
			v[mp[str2]].push_back(mp[str1]);
		}
		showgraph(v);
		get_apoint(v);
		cout<<"City map #"<<j<<": "<<artipt.size()<<" camera(s) found\n";
		set<string> st;
		for(int i=0;i<artipt.size();i++)
		{
			st.insert(str[i]);
		}
		set<string>:: iterator p = st.begin();
		while(p!=st.end())
		{
			cout<<*p<<endl;
			p++;
		}
		st.clear();
		mp.clear();
		v.clear();
		artipt.clear();
	}
}
