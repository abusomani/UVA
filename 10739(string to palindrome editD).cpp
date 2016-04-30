#include<bits/stdc++.h>
#define M 100
using namespace std;
int min(int a,int b,int c)
{
	return min(a , min(b,c));
}
int ed[M][M];
string str;

int solve(int i,int j)
{
//	cout<<i<<"  "<<j<<endl;
	if(i<0 || j>str.length())
		return INT_MAX;
	

	if(ed[i][j] != -1)		{	return ed[i][j];	}
	
//	cout<<"sda\n";
	if(j-i == 0)			{	return 0;    		}
	
	
//	cout<<"sdas\n";
	if(j-i == 1)
	{
		if(str[i] == str[j])
			return 0;
		else
			return 1;
	}
	
//	cout<<"sdaaz\n";
	if(str[i] == str[j])
		ed[i][j] = solve(i+1,j-1);
	else
		ed[i][j] = 1 + min(solve(i+1,j) , solve(i,j-1) , solve(i+1,j-1));
	return ed[i][j];
}

int main()
{
	int t;
	cin>>t;
	for(int s=1 ; s<=t ; s++)
	{
		memset(&ed,-1,sizeof(ed));
		cin>>str;
		
		printf("Case %d: %d\n",s,solve(0,str.length()-1));
	}
}
