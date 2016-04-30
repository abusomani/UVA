#include<bits/stdc++.h>
#define M 32
using namespace std;
char a[M][M][M];
int dis[M][M][M];
bool visit[M][M][M];

int si,sj,sk,ei,ej,ek;
int l,r,c;

struct cod
{
	int i,j,k;
	cod(int ii,int jj,int kk):i(ii),j(jj),k(kk)
	{}
	cod()
	{}
};

bool operator==(cod& a,cod& b)
{
	if(a.i == b.i and a.j == b.j and a.k == b.k)
		return 1;
	return 0;
}

bool ok(int i,int j,int k)
{
	if(i>=0 and i<l and j>=0 and j<r and k>=0 and k<c and a[i][j][k] != '#' and !visit[i][j][k])
		return 1;
	return 0;
}

int bfs()
{
	queue<cod> q;
	q.push(cod(si,sj,sk));
	int i,j,k;
	cod tmp;
	cod end(ei,ej,ek);
	dis[si][sj][sk] = 1;
	while(!q.empty())
	{
		tmp = q.front();	q.pop();
		i = tmp.i;	j = tmp.j;	k = tmp.k;
		visit[i][j][k] = 1;
		if(i == ei and j == ej and k == ek)
		{	return dis[ei][ej][ek];	}
		
		if(ok(i,j,k-1))		{	dis[i][j][k-1] = dis[tmp.i][tmp.j][tmp.k] + 1;		q.push(cod(i,j,k-1));	}
		if(ok(i,j,k+1))		{	dis[i][j][k+1] = dis[tmp.i][tmp.j][tmp.k] + 1;		q.push(cod(i,j,k+1));	}
		if(ok(i-1,j,k))		{	dis[i-1][j][k] = dis[tmp.i][tmp.j][tmp.k] + 1;		q.push(cod(i-1,j,k));	}
		if(ok(i+1,j,k))		{	dis[i+1][j][k] = dis[tmp.i][tmp.j][tmp.k] + 1;		q.push(cod(i+1,j,k));	}
		if(ok(i,j-1,k))		{	dis[i][j-1][k] = dis[tmp.i][tmp.j][tmp.k] + 1;		q.push(cod(i,j-1,k));	}
		if(ok(i,j+1,k))		{	dis[i][j+1][k] = dis[tmp.i][tmp.j][tmp.k] + 1;		q.push(cod(i,j+1,k));	}
	}
	return -1;
}

int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	while(cin>>l>>r>>c)
	{
		if(!l and !r and !c)	break;
		memset(&visit,0,sizeof(visit));
		for(int i = 0 ; i<l ; i++)
		{
			for(int j=0 ; j<r ; j++)
			{
				for(int k=0 ; k<c ; k++)
				{
					cin>>a[i][j][k];
					if(a[i][j][k] == 'S')
						{	si = i;		sj = j;		sk = k;		}
					
					if(a[i][j][k] == 'E')	
						{	ei = i;		ej = j;		ek = k;		}
				}
			}
		}
		int k = bfs();
		for(int i = 0 ; i<l ; i++)
		{
			for(int j=0 ; j<r ; j++)
			{
				for(int k=0 ; k<c ; k++)
				{
					cout<<visit[i][j][k]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		if(k == -1)
		{	   printf("Trapped!\n");	    }
		else
		{      printf("Escaped in %d minute(s).",k);		}
	}
}
