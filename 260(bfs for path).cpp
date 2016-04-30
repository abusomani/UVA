#include<bits/stdc++.h>
#define M 205
using namespace std;
typedef pair<int,int> ii;

string str[M];
int n;
bool ok(int a,int b)
{
	if(a>=0 and b<n and str[a][b] == 'b')
		return 1;
	return 0;	
}

int main()
{
	int a,b;		bool f;
	ii t;
	bool visit[M][M];
	int j = 0;
	int dx[] = {-1,-1,0,0,1,1};
	int dy[] = {-1,0,-1,1,0,1};
	while(cin>>n and n)
	{
		queue<ii> qb;
		j++;	f = 0;
		for(int i=0;i<n;i++)
			cin>>str[i];
		
		memset(&visit,0,sizeof(visit));
		// For black
		
		for(int i=0;i<n;i++)
		{
			if(str[0][i] == 'b')
				qb.push(ii(0,i));
		}
		while(!qb.empty())
		{
			t = qb.front();		qb.pop();
			a = t.first;		b = t.second;
			if(a == n-1)
			{	cout<<j<<" B\n";	f = 1;		break;	}
			for(int i=0;i<6;i++)
			{
				if(ok(a+dx[i] , b+dy[i]) and !visit[a+dx[i]][b+dy[i]] )
				{
					qb.push(ii(a+dx[i] , b+dy[i]));
					visit[a+dx[i]][b+dy[i]] = 1;
				}
			}
		}
		if(!f)
		{	cout<<j<<" W\n";	}
	}
}
