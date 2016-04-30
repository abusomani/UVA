#include<bits/stdc++.h>
#define M 110
using namespace std;
int main()
{
	int m,n;
	int s = 0;
	int L[M][M];
	int a[M],b[M];
	while(cin>>m>>n && m && n)
	{
		s++;
		memset(&L,0,sizeof(L));
		for(int i=0;i<m;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(i==0 || j==0)
					L[i][j] = 0;
				else
				{
					if(a[i-1] == b[j-1])
						L[i][j] = L[i-1][j-1] + 1;
					else
						L[i][j] = max( L[i-1][j],L[i][j-1] );
				}
			}
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",s,L[m][n]);
	}
}
