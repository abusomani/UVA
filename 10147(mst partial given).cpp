// uva 10147  to be submitted

#include <bits/stdc++.h>
using namespace std;
#define M 1205
#define sqr(x)  ((x)*(x))
typedef pair<int,int> ii;
int s[M];
double dis(ii x,ii y)
{
	return  sqrt( sqr(x.first - y.first) + sqr(x.second - y.second) );
}
int find(int i)
{
    if(s[i]<0)
        return i;
    else
        return s[i] = find(s[i]);
}
void dounion(int i,int j)
{
    i = find(i);
    j = find(j);
    if(i == j)	return;
    if(s[i] > s[j])
    {
        s[j] += s[i];
        s[i] = j;
    }
    else
    {
        s[i] += s[j];
        s[j] = i;
    }
}

int main()
{
    int t,e;
    int a,b,m;
    int x,y;
    ii u;
    cin>>t;
    while(t--)
    {
    	vector<ii> pt;
    	bool flag = 0;
        memset(&s,-1,sizeof(s));
    	vector< pair<double,ii> > edge;
    	cin>>e;
    	for (int i = 0; i < e; ++i)
    	{
    		cin>>x>>y;
    		pt.push_back(make_pair(x,y));
    	}
    	for (int i = 0; i < e; ++i)
    	{
    		for (int j = i+1; j < e; ++j)
    		{
    			edge.push_back(make_pair(dis(pt[i] , pt[j]) , ii(i,j)));
    		}
    	}
    	sort(edge.begin(),edge.end());
    	cin>>m;
        for (int i = 0; i < m; ++i)
        {
            cin>>a>>b;
            a--;	b--;
            dounion(a,b);
        }
        for(int i=0 ; i<edge.size() ; i++)
    	{
    		u = edge[i].second;
            if(find(u.first) != find(u.second))
            {
                dounion(u.first , u.second);
                cout<<(u.first+1)<<" "<<(u.second+1)<<endl;
           		flag = 1;
		    }
    	}
    	if(!flag)
    		cout<<"No new highways need\n";
        /*sort(ans.begin(),ans.end());
        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
        }*/
        if(t)
			cout<<endl;
    	pt.clear();
    	edge.clear();
    }
}
