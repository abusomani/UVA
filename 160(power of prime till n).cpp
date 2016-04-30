#include<bits/stdc++.h>
#define M 108
using namespace std;
bool mark[M+2];

int pcount[M+2][M+2];
void markmultiples(int n,int k)
{
	int keep;
	pcount[k][k] = 1;
	for(int i=k+k;i<n;i+=k)
	{
		keep = i;
		mark[i] = 1;
		while(keep % k==0)
		{
			keep /= k;
			pcount[i][k]++;
		}
	}
}
void sieve(int n)
{
	memset(&mark,0,sizeof(mark));
	for(int i=2;i<n;i++)
	{
		if(mark[i] == 0)
		{
			markmultiples(n,i);
		}
	}
}
int main()
{
	memset(&pcount,0,sizeof(pcount));
	sieve(M);
	
	for(int i=2;i<M;i++)
	{
		for(int j=2;j<M;j++)
		{
			pcount[i][j] += pcount[i-1][j];
		}
	}
	int n;
	while(cin>>n)
	{
		if(!n)		break;
		printf("%3d! =",n);
		int ct = 0;
		for(int i=2;i<=n;i++)
		{
			if(mark[i] == 0)
			{
				printf("%3d",pcount[n][i]);
				ct++;
			}
			if(ct == 15)
			{
				printf("\n      ");
				ct = 0;
			}
		}
		printf("\n");
	}
}
