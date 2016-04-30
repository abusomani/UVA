//	In this question we need to get sp from 0 to n-1 with condition that only k nodes should be visited in between them
//	More optimise O(n^2) ( this is O(n^3) )  is variation of bellman ford algorithm (online available)

#include <bits/stdc++.h>
using namespace std;
#define M 105
#define MAX 123456789
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

void showgraph(vvii& g)
{
	for(int i=0;i<g.size();i++)
	{
		cout<<i<<" : ";
		for(int j=0;j<g[i].size();j++)
		{
			cout<<g[i][j].first<<" ("<<g[i][j].second<<")   ";
		}
	}
}
int main()
{
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    int n,t,e,v,wt,q,step,ans;
	int dis[M][M];
	
    cin>>t;
    string str[M] , str1 ,str2;
    map<string,int> mp;
    for (int cas = 1; cas <= t ; cas++)
    {
        cin>>n;
        vvii g(n+1);
        
		for (int i = 0; i < n; ++i)
        {
            cin>>str[i];    
		}
		mp["Calgary"] = 0;			mp["Fredericton"] = n-1;
		for (int i = 1; i < n-1; ++i)
        {
        	if(str[i] != "Calgary" or str[i] != "Fredericton")
            	mp[str[i]] = i;  
		}
        cin>>e;
        for (int i = 0; i < e; ++i)
        {
            cin>>str1>>str2>>wt;
            g[mp[str1]].push_back(ii(mp[str1] , wt));
        }
        //showgraph(g);
        for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= n; ++j)
				dis[i][j] = MAX;
		}
		
		for (int i = 0; i < g[0].size(); ++i)
        {
            v = g[0][i].first;      wt = g[0][i].second;
            dis[v][0] = wt; 
        }
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < g[i].size(); ++j)
            {
                for (int k = 1; k < n-1; ++k)
                {
                    v = g[i][j].first;      wt = g[i][j].second;
                    dis[v][k] = min(dis[v][k] , dis[i][k-1] + wt);
       //             cout<<i<<" "<<j<<" "<<k<<" "<<v<<" "<<wt<<" "<<dis[v][k]<<endl;
                }
            }
        }
       
        cin>>q;
        printf("Scenario #%d\n",cas);
        while(q--)
        {
            cin>>step;
            step = min(step , n-2);
            ans = MAX;
            for (int i = 0; i <= step; ++i)
            {
                ans = min(ans , dis[n-1][i]);
            }
            if(ans != MAX)
            	printf("Total cost of flight(s) is $%d\n", ans);
        	else
        		printf("No satisfactory flights\n");
		}
        printf("\n");
        g.clear();
    	mp.clear();    
	}
}
