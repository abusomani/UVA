//	Uva 821

#include <bits/stdc++.h>
#define M 302
#define MAX 123456789
using namespace std;
int max(int a,int b,int c)
{
    return max(a,max(b,c));
}
int main()
{
    int n;
    int a[10000],k,l;
    int g[M][M];
    int dis[M][M];
    int j = 1;
    while(cin>>a[0]>>a[1])
    {
    	if(a[0] == 0 and a[1] == 0)	break;
        memset(&g,0,sizeof(g));
        set<int> st;
		st.insert(a[0]);		st.insert(a[1]);
        k = 2;  l = 3;
		while(cin>>a[k]>>a[l])
        {
        	if(a[k] == 0 and a[l] == 0)		break;
        	st.insert(a[k]);		st.insert(a[l]);
        	k += 2;		l += 2;
		}
		n = st.size();
		k = 0;
		set<int>:: iterator p = st.begin();
		map<int,int> mp;
		while(p != st.end())
		{
			mp[*p] = k++;
			p++;
		}
		k = 0;
		for(int i=0;i<l/2;i++)
		{
			g[mp[a[k]]][mp[a[k+1]]] = 1;
			k += 2;
		}
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<g[i][j]<<"   ";
			}
			cout<<endl;
		}   */
	  	for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
            	if(g[i][j] != 0)	dis[i][j] = g[i][j];
				else				dis[i][j] = MAX;
				if(i == j)			dis[i][j] = 0;
			}
        }
        
		for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {		
                for (int j = 0; j < n; ++j)
                {
                    dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
          //      cout<<dis[i][j]<<"  ";
                sum += dis[i][j];
            }
           // cout<<endl;
        }
        printf("Case %d: average length between pages = %.3f clicks\n",j,(double)sum / (n*(n-1)));
        j = j+1;
        mp.clear();
        st.clear();
    }
}
