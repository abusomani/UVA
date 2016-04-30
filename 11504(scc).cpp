//  actually it is uva - 11709  (but same SCC based)
#include<bits/stdc++.h>
#define M 10005
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

stack<int> st;
bool visit[M];	

void flip(vvi& g, vvi& revg)
{
	for(int i=0;i<g.size();i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			revg[g[i][j]].push_back(i);
		}
	}
}

void dfsnum(vvi& g,int k)
{
	visit[k] = 1;
	for(int i=0;i<g[k].size();i++)
	{
		if(!visit[g[k][i]])
			dfsnum(g,g[k][i]);
	}
	st.push(k);
}
void dfs(vvi& g,int k)
{
	visit[k] = 1;
	for(int i=0;i<g[k].size();i++)
	{
		if(!visit[g[k][i]])
			dfs(g,g[k][i]);
	}
}
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
void scc(vvi& g)
{
	int k;
	int ct = 0;
	memset(&visit,0,sizeof(visit));
	for(int i=0;i<g.size();i++)
	{
		if(!visit[i])
			dfsnum(g,i);
	}
	vvi revg(g.size());
	flip(g,revg);
	memset(&visit,0,sizeof(visit));
	while(!st.empty())
	{
		k = st.top();		st.pop();
		if(!visit[k])
		{
			dfs(revg,k);				//	here for printing scc's put cout in dfs and then 
										//	new line here
			ct++;
		}
	}
	cout<<ct<<endl;
}

void flood_fill(vvi& g)
{
	int ct = 0;
	memset(&visit,0,sizeof(visit));
	for(int i=0;i<g.size();i++)
	{
		if(!visit[i])
		{
			dfs(g,i);
			ct++;
		}
	}	
	cout<<ct<<endl;
}
 
int main()
{
	int n,e;
	map<string,int> mp;
	string str,str2;
	while(cin>>n>>e)
	{
		if(n==0 and e==0)	break;
		vvi g(n);
		getchar();
		for(int i=0;i<n;i++)
		{
			getline(cin,str);
			mp[str] = i;
		}
		/*
		map<string,int>:: iterator p = mp.begin();
		while(p!=mp.end())
		{
			cout<<p->first<<endl;
			p++;
		}
		*/
		for(int i=0;i<e;i++)
		{
			getline(cin,str);
			getline(cin,str2);
			g[mp[str]].push_back(mp[str2]);
		}
	//	showgraph(g);
		scc(g);
		g.clear();
		mp.clear();
	}
	
}
