#include <bits/stdc++.h>
using namespace std;
#define MAX 123456789
#define M 100
typedef pair<int,int> ii;
using namespace std;
string sch(map<string,int>& mp,int k)
{
	map<string,int>:: iterator p = mp.begin();
	while(p != mp.end())
	{
		if(p->second == k)
			return p->first;
		p++;
	}
}
int main()
{
	string str1,str2;
	vector<ii> v;
	int n,p,cas = 0;
	int k = 0;
	int g[M][M];
	int dis[M][M];
	map<string,int> mp;
	while(cin>>n and n)
	{
		cas++;
		k = 0;
		memset(&g,0,sizeof(g));
		for(int i=0 ; i<n ; i++)
		{
			cin>>p;
			cin>>str1;
			if(mp.find(str1) == mp.end())
				mp[str1] = k++;
			for(int j=1 ; j<p ; j++)
			{
				cin>>str2;
				if(mp.find(str2) == mp.end())
					mp[str2] = k++;
				g[mp[str1]][mp[str2]] = 1;
				str1 = str2;
			}
		}
		cin>>p;
		for(int i=0 ; i<p ; i++)
		{
			cin>>str1>>str2;
			g[mp[str1]][mp[str2]] = 1;
		}
		for(int i=0 ; i<k ; i++)
		{
			for(int j=0 ; j<k ; j++)
			{
				if(g[i][j] != 0)	dis[i][j] = g[i][j];
				else				dis[i][j] = MAX;
				if(i == j)			dis[i][j] = 0;
			}
		}
		
		for(int l=0 ; l<k ; l++)
		{
			for(int i=0 ; i<k ; i++)
			{
				for(int j=0 ; j<k ; j++)
				{
					dis[i][j] = min(dis[i][j] , dis[i][l] + dis[l][j]);
				}
			}
		}
		
		int ct = 0;
		for(int i=0 ; i<k ; i++)
		{
			for(int j=i+1 ; j<k ; j++)
			{
				if(dis[i][j] == MAX)
				{
					ct++;
					if(v.size() < 2)
						v.push_back(ii(i,j));
				}
			}
		}
		if(ct == 0)
			printf("Case %d, no concurrent events.",cas);
		else
		{
			printf("Case %d, %d concurrent events: \n",cas,ct);
			if(v.size() == 1)
			{
				cout<<"("<<sch(mp,v[0].first)<<","<<sch(mp,v[0].second)<<")\n";
			}		
			else
			{
				cout<<"("<<sch(mp,v[0].first)<<","<<sch(mp,v[0].second)<<") ("<<sch(mp,v[1].first)<<","<<sch(mp,v[1].second)<<")\n";
			}
		}
	}
}
