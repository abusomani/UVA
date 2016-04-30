#include<bits/stdc++.h>
#define M 2147483647
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

void showgraph(vvii& g)
{
	for(int i=0;i<6;i++)
	{
		cout<<(i)<<"  : ";
		for(int j=0;j<g[i].size();j++)
		{
			cout<<g[i][j].first<<"  ("<<g[i][j].second<<")  "<<"   ";
		}
		cout<<endl;
	}
}

int n;
int sp(vvii& g,int source,int desti)
{
	vi dis(3*n,M);
	ii k ;
	int a,b,pathlen,weight;
	set<ii> s;
	s.insert(ii(0,source));
	
	dis[source] = 0;
	
	while(!s.empty())
	{
		k = *(s.begin());		s.erase(s.begin());	
		pathlen = k.first;		a = k.second;		
		for(int i=0;i<g[a].size();i++)
		{
			b = g[a][i].first;		weight = g[a][i].second;
			if(dis[b] > dis[a] + weight)
			{
				if(dis[b]!=M)	{		s.erase(s.find(ii(dis[b],b)));		}
				dis[b] = dis[a] + weight;
			    s.insert(ii(dis[b],b));
			}
		}
	}
	return dis[desti];
}
int main()
{
	map<string,int> mp;
	map<ii,int> st;
	map<ii,int>:: iterator p;
	string str1,str2,str3,so,de;
	
	int k,a,b,s,d;
	while(1)
	{
		cin>>n;
		if(!n)	break;
		vvii g(3*n);
		cin>>so>>de;
		k = 0;
		mp.clear();
		st.clear();
		g.clear();
		for(int i=0;i<n;i++)
		{
			cin>>str1>>str2>>str3;
			if(!mp.count(str1))
				mp[str1] = k++;
			
			if(!mp.count(str2))
				mp[str2] = k++;
			
			a = mp[str1];		b = mp[str2];
		
			if(a>b)		swap(a,b);
			
			if(st.find(ii(a,b)) != st.end())		// storing in set to get rid of parallel edges
			{
				if(str3.length() < st[ii(a,b)])
				{
					st.erase(ii(a,b));
					st[ii(a,b)] = str3.length();
				}
			}
			else
			{
				st[ii(a,b)] = str3.length();
			}
		}
	
		p = st.begin();
		
		while(p != st.end())
		{
			g[p->first.first].push_back(ii(p->first.second,p->second));
			g[p->first.second].push_back(ii(p->first.first,p->second));
		
			p++;
		}
		
		//showgraph(g);
		if(!mp.count(so) || !mp.count(de))
		{	cout<<"impossivel\n";   continue;	}
		s = mp[so];		d = mp[de];
		
		k = sp(g,s,d);
		
		if(k==M)	cout<<"impossivel\n";
		else		cout<<k<<endl;
		
	
	}
}
