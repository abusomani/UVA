//  2 times bfs is necessary to get diameter

//	program still not working.

#include <bits/stdc++.h>
#define M 1003
using namespace std;

int dis1[M];
int dis2[M];
bool visit[M];
vector<vector<pair<int,int> > > g(M);
int n;
int max1,max2;

int bfs(int s,bool on)
{
	int u,v;
	memset(&visit,0,sizeof(visit));
	memset(&dis1,0,sizeof(dis1));
	memset(&dis2,0,sizeof(dis2));
	
	max1 = max2 = 0;
	queue<int> q;
	q.push(s);
	dis1[s] = 0;		dis2[s] = 0;			
	visit[s] = 1;
	while(!q.empty())
	{
		u = q.front();		  q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			v = g[u][i].second;
			if(!visit[v])
			{
				cout<<u+1<<"  "<<v+1<<"  "<<g[u][v].first<<endl;
				visit[v] = 1;	
				dis1[v] = dis1[u] + 1;
				dis2[v] = dis2[u] + g[u][v].first;
				q.push(v);
			}
		}
	}	
	for(int i=0;i<n;i++)
	{
		cout<<i<<"  "<<dis1[i]<<"  "<<dis2[i]<<endl;
		if(max1 <= dis1[i])
		{
			if(dis1[i] == max1)
			{
				if(dis2[i] > max2)
				{
					s = i;
					max1 = dis1[i];
					max2 = dis2[i];
				}
			}
			else
			{
				s = i;
				max1 = dis1[i];
				max2 = dis2[i];	
			}
		}
	}
	return s;
}

int main()
{
	int st;
	n = 1;
	int a,b,w;
	string line;
	while(getline(cin, line))
	{
    	if(line == "")
		{
   		    st = bfs(0,1);
   		    cout<<"st"<<st<<endl;
			bfs(st,0);
			cout<<max2<<endl;
			g.clear();
			n = 1;
			continue;
    	}
		stringstream ss(line);
	    ss >> a >> b >> w;
	    a--;	b--;
	    n++;
		g[a].push_back(make_pair(w,b));
		g[b].push_back(make_pair(w,a));
  	}
}
