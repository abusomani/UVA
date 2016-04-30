#include <bits/stdc++.h>
using namespace std;
#define M 2005
struct graph
{
	int a,b,wt;
	graph(int aa,int bb,int w):a(aa),b(bb),wt(w)
	{}
	graph()
	{}
};

void swap(graph& x,graph& y)
{
	swap(x.a , y.a);
	swap(x.b , y.b);
	swap(x.wt , y.wt);	
}

int main()
{
    int t,a,b,n,e,i,j,wt;
    int dis[M];
    graph g[M];
	cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);

    cin>>t;
    while(t--)
    {
        cin>>n>>e;
        for (i = 0; i < e; ++i)
        {
            cin>>a>>b>>wt;
            g[i] = graph(a,b,wt);
        }
        for (i = 0; i < n; ++i)
        {
            dis[i] = INT_MAX; 
        }
        for(i = 0; i < e ; ++i)
        {
        	if(g[i].a == 0)
        	{
        		swap(g[i],g[0]);
        		break;
        	}
        }
        dis[0] = 0;
        for (i = 1; i < n; ++i)
        {
            for (j = 0; j < e; ++j)
            {
            	a = g[j].a;		b = g[j].b;		wt = g[j].wt;
            	if(dis[a] != INT_MAX and dis[b] > dis[a] + wt)
                    dis[b] = dis[a] + wt;
            }
        }
        /*
        for (i = 0; i < e; ++i)
        	cout<<dis[i]<<endl;
		*/
        for (i = 0; i < e; ++i)
        {
        	a = g[i].a;		b = g[i].b;		wt = g[i].wt;
            if(dis[a] != INT_MAX and dis[b] > dis[a] + wt)
			    break;
        }
        if (i == e)
            cout<<"not possible";
        else
            cout<<"possible";
        cout<<endl;
    }
}
