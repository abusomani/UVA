#include<bits/stdc++.h>
#define M 100
using namespace std;
int dp[M][M];
char str[M];

int solve(int i,int j)
{
	if(dp[i][j] != -1)		return dp[i][j];
	if(i == j)
		return 1;
	if(j-i == 1)
	{
		if(str[i] == str[j])
			return 2;
		else
			return 1;
	}
	if(str[i] == str[j])
		dp[i][j] = 2 + solve(i+1,j-1);
	else
		dp[i][j] = max( solve(i+1,j) , solve(i,j-1) );
	return dp[i][j]; 
}
int main()
{
	int tc;
	scanf("%d", &tc);
	getc(stdin);

	while (tc--) {
		gets(str);

		if (strlen(str) == 0) {
			printf("0\n");
			continue;
		}

		memset(&dp,-1,sizeof(dp));
		cout<<solve(0,strlen(str)-1)<<endl;
	}
}
