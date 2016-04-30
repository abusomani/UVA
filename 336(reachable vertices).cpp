// 	problem based on vertices which are reachable from a particular node in a given range
//  used bfs for getting nodes out of range but main point is initialising dis from big value
//	so that if they are not connected then they will also be counted.

#include<bits/stdc++.h>
#define M 214748364
using namespace std;
int main()
{
	int n,a,b,k;
	int j=1;
	map<int,vector<int> > mp;
	map<int,vector<int> > :: iterator p;
	map<int,bool> visited;
	map<int,int> dis;
	while(1)
	{
		mp.clear();
		cin>>n;
		if(!n)		break;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		while(1)
		{
			cin>>a>>b;
			if(a==0 && b==0)	break;
			queue<int> q;
			q.push(a);
			p = mp.begin();
			while(p!=mp.end())
			{
				visited[p->first] = 0;
				dis[p->first] = M;
				p++;
			}
			visited[a] = 1;
			dis[a] = 0;
			while(!q.empty())
			{
				k = q.front();		q.pop();
				vector<int>& v = mp[k];
				for(int i=0;i<v.size();i++)
				{
					if(!visited[v[i]])
					{
						visited[v[i]] = 1;
						dis[v[i]] = dis[k] + 1;
						q.push(v[i]);
					}
				}
			}
			p = mp.begin();
			int ct = 0;
			while(p!=mp.end())
			{
				//cout<<p->first<<"  "<<dis[p->first]<<endl;
				if(dis[p->first]>b)
					ct++;
				p++;
			}
			cout<<"Case "<<j++<<": "<<ct<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<".\n";
		}
	}
}
