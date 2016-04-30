#include <bits/stdc++.h>
#define M 1005
using namespace std;
typedef pair<int,int> ii;

bool a[M][M];
int dis[M][M];
bool visit[M][M];
int m,n;
ii start,end;

bool ok(int i,int j)
{
	if(i>=0 and i<m and j>=0 and j<n and !visit[i][j] and a[i][j])
		return 1;
	return 0;
}
int bfs()
{
	queue<ii> q;
	q.push(start);
	int i,j;
	ii t;
	while(!q.empty())
	{
		t = q.front();		q.pop();
		i = t.first;		j = t.second;
		if(t == end)
		{	return dis[i][j];	}
		visit[i][j] = 1;
		if(ok(i-1,j))	{	dis[i-1][j] = dis[i][j] + 1;	q.push(ii(i-1,j));		}
		if(ok(i,j-1))	{	dis[i][j-1] = dis[i][j] + 1;	q.push(ii(i,j-1));		}
		if(ok(i,j+1))	{	dis[i][j+1] = dis[i][j] + 1;	q.push(ii(i,j+1));		}
		if(ok(i+1,j))	{	dis[i+1][j] = dis[i][j] + 1;	q.push(ii(i+1,j));		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int row,k,p,r,si,sj,ei,ej;
	while(cin>>m>>n)
	{
		if(!m and !n)	break;
		cin>>row;
		memset(&a,1,sizeof(a));
		memset(&visit,0,sizeof(visit));
		for (int i = 0; i < row; ++i)
		{
			cin>>r>>p;
			for (int j = 0; j < p; ++j)
			{
				cin>>k;
				a[r][k] = '0';
			}
		}
		cin>>si>>sj;
		start = make_pair(si,sj);
		cin>>ei>>ej;
		end = make_pair(ei,ej);
		cout<<bfs()<<endl;
	}
}
