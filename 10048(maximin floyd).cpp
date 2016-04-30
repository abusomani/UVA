//	Maximin problem solvable by variation of floyd warshall - here we need to get min wt edge in path btw any two vertices.
#include <bits/stdc++.h>
#define MAX 123456789
#define M 103
using namespace std;
int main()
{
	int n,e,q,a,b,wt;
	int g[M][M];
	int pathmin[M][M];				//	it will store min edge wt of every path from i to j
	int cas = 1;
	while(cin>>n>>e>>q)
	{
		if(n==0 and e==0 and q==0)		break;
		memset(&g,0,sizeof(g));
		for(int i=0;i<e;i++)
		{
			cin>>a>>b>>wt;
			a--;	b--;
			g[a][b] = wt;
			g[b][a] = wt;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(g[i][j] != 0)	pathmin[i][j] = g[i][j];
				else				pathmin[i][j] = MAX;
			}
		}
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<pathmin[i][j]<<"  ";
			}
			cout<<endl;
		}
		*/
		
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					pathmin[i][j] = min(pathmin[i][j] , max(pathmin[i][k] , pathmin[k][j]));
				}
			}
		}
		printf("Case #%d\n",cas);
		while(q--)
		{
			cin>>a>>b;
			a--;	b--;
			if(pathmin[a][b] == MAX)	cout<<"no path\n";
			else						cout<<pathmin[a][b]<<endl;
		}
		cas++;
		cout<<endl;
	}
}
