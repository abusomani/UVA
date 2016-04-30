#include <bits/stdc++.h>
#define M 1005
using namespace std;
typedef pair<int,int> ii;

int n,a,b;
bool visit[M][M];
char grid[M][M];
int dis[M][M];
int fire[M][M];

queue<ii> qj , qf;

bool out_of_maze(ii t)
{
	int i,j;
	i = t.first;	j = t.second;
	if(i==0 or i==a-1 or j==0 or j==b)
		return 1;
 	return 0;
}

bool ok1(int i,int j)
{
	if(!visit[i][j] and grid[i][j] != '#' and ( fire[i][j] == -1 or dis[i][j] < fire[i][j] ))
		return 1;
	return 0;
}

bool ok(int i,int j)
{
	if(i>=0 and i<a and j>=0 and j<b and grid[i][j] != '#' and !visit[i][j] and fire[i][j] == -1)
		return 1;
	return 0;
}

void printvisit()
{
	for(int i = 0 ; i < a ; i++)
	{
		for (int j = 0; j < b; ++j)
			cout<<visit[i][j]<<"  ";
		cout<<endl;
	}
	cout<<endl;
}

void printfire()
{
	for(int i = 0 ; i < a ; i++)
	{
		for (int j = 0; j < b; ++j)
			cout<<fire[i][j]<<"  ";
		cout<<endl;
	}
	cout<<endl;
}

void bfs_fire()
{	
	int i,j;
	ii t;
		
	while(!qf.empty())
	{
		t = qf.front();		qf.pop();
		i = t.first;		j = t.second;
		visit[i][j] = 1;
		if(ok(i-1,j))		{	qf.push(ii(i-1,j));		fire[i-1][j] = fire[i][j] + 1;	}
		if(ok(i,j-1))		{	qf.push(ii(i,j-1));		fire[i][j-1] = fire[i][j] + 1;	}
		if(ok(i,j+1))		{	qf.push(ii(i,j+1));		fire[i][j+1] = fire[i][j] + 1;	}
		if(ok(i+1,j))		{	qf.push(ii(i+1,j));		fire[i+1][j] = fire[i][j] + 1;	}

	}
}
int bfs()
{
	int i,j;
	int u,v;
	ii t;
	bool f;
	t = qj.front();

	dis[t.first][t.second] = 0;
	
	while(!qj.empty())
	{
		f = 0;
		t = qj.front();		qj.pop();
		
		i = t.first;		j = t.second;
		if(out_of_maze(t) == 1)
			return dis[i][j];
		visit[i][j] = 1;
		
		u = i-1;	v = j;
		if(u>=0 and u<a and v>=0 and v<b)
		{
			(dis[i-1][j] = dis[i][j] + 1);
			if(ok1(i-1,j))
			{	qj.push(ii(i-1,j));	f = 1;	}	
		}
		
		u = i;	v = j-1;
		if(u>=0 and u<a and v>=0 and v<b)
		{
			(dis[i][j-1] = dis[i][j] + 1);
			if(ok1(i,j-1))
			{	qj.push(ii(i,j-1));	f = 1;	}	
		}

		u = i;	v = j+1;
		if(u>=0 and u<a and v>=0 and v<b)
		{
			(dis[i][j+1] = dis[i][j] + 1);
			if(ok1(i,j+1))
			{	qj.push(ii(i,j+1));	f = 1;	}	
		}

		u = i+1;	v = j;
		if(u>=0 and u<a and v>=0 and v<b)
		{
			(dis[i+1][j] = dis[i][j] + 1);
			if(ok1(i+1,j))
			{	qj.push(ii(i+1,j));	f = 1;	}	
		}

	//	printvisit();
		if(!f)	return -1;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
	
		memset(&fire,-1,sizeof(fire));
		for(int i = 0 ; i < a ; i++)
		{
			for (int j = 0; j < b; ++j)
			{
				cin>>grid[i][j];
				if(grid[i][j] == 'F')
				{	
					fire[i][j] = 0;
					visit[i][j] = 1;
					qf.push(ii(i,j));
				}
				if(grid[i][j] == 'J')
				{
					qj.push(ii(i,j));
				}
				if(grid[i][j] == '#')
					visit[i][j] = 1;
			}
		}
		memset(&visit,false,sizeof(visit));
	//	printfire();
		bfs_fire();
		memset(&visit,false,sizeof(visit));
	//	printfire();	
		int k = bfs();
		if(k == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",k+1);
	
		while(!qj.empty())
			qj.pop();
		while(!qf.empty())
			qf.pop();
	}
}
