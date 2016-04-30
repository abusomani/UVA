//	uva 10034

#include <bits/stdc++.h>
using namespace std;
#define M 1005
#define sqr(x)  ((x)*(x))
typedef pair<double,double> ii;
int s[M];
double dis(ii x,ii y)
{
	return  sqr(x.first - y.first) + sqr(x.second - y.second);
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
    if(s[i] >= s[j])
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
    double x,y;
    ii u;
    cin>>t;
    while(t--)
    {
    	vector<ii> pt;
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
    			edge.push_back(make_pair(sqrt(dis(pt[i] , pt[j])) , ii(i,j)));
    	//		cout<<dis(pt[i] , pt[j])<<endl;
    		}
    	}
    	sort(edge.begin(),edge.end());
    	double ans = 0.0;
		for(int i=0 ; i<edge.size() ; i++)
    	{
    		u = edge[i].second;
            if(find(u.first) != find(u.second))
            {
                dounion(u.first , u.second);
                ans += edge[i].first;
            //    cout<<u.first<<"   "<<u.second<<endl;
            }
    	}
    	printf("%.2f\n\n",ans);
		pt.clear();
    	edge.clear();
    }
}
