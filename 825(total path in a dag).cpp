#include <bits/stdc++.h>
#define M 105
using namespace std;
typedef pair<int,int> ii;
bool g[M][M];
int ct[M][M];
bool visit[M][M];
int w,n;

int count_path()
{
	ii t;
	int i,j;
	memset(&visit,0,sizeof(visit));
	memset(&ct,0,sizeof(ct));
    queue<ii> q;
    q.push(ii(1,1));
    ct[1][1] = 1;
    while(!q.empty())
    {
        t = q.front();      q.pop();
        i = t.first;		j = t.second;
		if(g[i][j+1])
        {
            if(!visit[i][j+1])
            {
                visit[i][j+1] = 1;
                ct[i][j+1] = ct[i][j];
                q.push(ii(i,j+1));
            }
            else
            {
                ct[i][j+1] += ct[i][j];
            }
        }
        if(g[i+1][j])
        {
            if(!visit[i+1][j])
            {
                visit[i+1][j] = 1;
                ct[i+1][j] = ct[i][j];
                q.push(ii(i+1,j));
            }
            else
            {
                ct[i+1][j] += ct[i][j];
            }
        } 
    }
    return ct[w][n];
}

int main()
{
    int t,p,k;
    cin>>t;
    while(t--)
    {
        cin>>w>>n;
        for (int i = 1; i <= w; ++i)
        {
        	for (int j = 1; j <= n; ++j)
        		g[i][j] = 1;
        }
        cin.ignore();    // ignore '\n'
        string str;
        for (int i = 1, j; i <= w; ++i) 
		{
            getline(cin, str);
            stringstream ss(str);
            ss >> j;    // ignore the first number
            while (ss >> j)
                g[i][j] = 0;
        }

        // for (int i = 1; i <= w; ++i)
        // {
        // 	for (int j = 1; j <= n; ++j)
        // 		cout<<g[i][j]<<"  ";
        // 	cout<<endl;
        // }
        cout<<count_path()<<endl;
		if(t) cout << endl;
    	// for (int i = 1; i <= w; ++i)
     //   {
     //   	for (int j = 1; j <= n; ++j)
     //   		cout<<ct[i][j]<<"  ";
     //   	cout<<endl;
     //   }
    }
}
