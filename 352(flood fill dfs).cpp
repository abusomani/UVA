#include<bits/stdc++.h>
#define M 27
using namespace std;
typedef pair<int,int> ii;
bool visit[M][M];
string str[M];

int n;
bool ok(int a,int b)
{
	if(a>=0 and b<n and !visit[a][b] and str[a][b] == '1')
		return 1;
	return 0;
}

void dfs(ii t)
{
	int a = t.first;	int b = t.second;
	if(ok(a-1,b-1))		{	visit[a-1][b-1] = 1;	dfs(ii(a-1,b-1));	}
	if(ok(a-1,b))		{	visit[a-1][b] = 1;		dfs(ii(a-1,b));		}
	if(ok(a-1,b+1))		{	visit[a-1][b+1] = 1;	dfs(ii(a-1,b+1));	}
	if(ok(a,b-1))		{	visit[a][b-1] = 1;		dfs(ii(a,b-1));		}
	if(ok(a,b+1))		{	visit[a][b+1] = 1;		dfs(ii(a,b+1));		}
	if(ok(a+1,b-1))		{	visit[a+1][b-1] = 1;	dfs(ii(a+1,b-1));	}
	if(ok(a+1,b))		{	visit[a+1][b] = 1;		dfs(ii(a+1,b));		}
	if(ok(a+1,b+1))		{	visit[a+1][b+1] = 1;	dfs(ii(a+1,b+1));	}
}

int main()
{
	int ct;
	int j = 0;
	while(cin>>n)
	{
		j++;
		memset(&visit,0,sizeof(visit));
		ct = 0;
		for(int i=0;i<n;i++)
			cin>>str[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visit[i][j] and str[i][j] == '1')
				{
					ct++;	dfs(ii(i,j));
				}
			}
		}
		cout<<"Image number "<<j<<" contains "<<ct<<" war eagles.\n";
	}
}
