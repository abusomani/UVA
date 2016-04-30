//	uva 531
//	LCS problem with - Actual common substring

#include<bits/stdc++.h>
#define M 500
using namespace std;
string str1,str2;
int L[M][M];
void print_lcs(int i,int j)
{
	if(i==0 || j==0)
		return;
	if(str1[i-1] == str2[j-1])
	{
		print_lcs(i-1,j-1);
		cout<<str1[i-1];
	}
	else
	{
		if(L[i-1][j] >= L[i][j-1])
			print_lcs(i-1,j);
		else
			print_lcs(i,j-1);	
	}
}
int main()
{
	string str;
	str1 = str2 = "";
	int i = 0,idx;
	char lcs[M];
	while(getline(cin,str))
	{
		if(str == "#")
		{
			i++;
			if(i%2 == 1)
			{
				str2 = str1;
				str1 = "";
			}
			else
			{
				//	process
				int m = str1.length();
				int n = str2.length();
				memset(&lcs,0,sizeof(lcs));
				for(int i=0;i<=m;i++)
				{
					for(int j=0;j<=n;j++)
					{
						if(i==0 || j==0)
							L[i][j] = 0;
						else
						{
							if(str1[i-1] == str2[j-1])
								L[i][j] = L[i-1][j-1] + 1;
							else
								L[i][j] = max( L[i-1][j] , L[i][j-1] );
						}						
					}
				}
			/*	for(int i=0;i<=m;i++)
				{
					for(int j=0;j<=n;j++)
					{	
						cout<<L[i][j]<<"  ";
					}	
					cout<<endl;
				}*/
				int i = m;
				int j = n;
				print_lcs(i,j);
				cout<<endl;
			/*	while(1)
				{
					if(L[i][j] == 0)		break;
					if(str1[i-1] == str2[j-1])
					{
						lcs[idx--] = str1[i-1];
						i--;	j--;
					}
					else
					{
						if(L[i][j] == L[i-1][j])
							i--;
						else
							j--;
					}
				}
				cout<<lcs<<endl;*/
				str1 = str2 = "";
			}
		}
		else
			str1 += str;
	}
}
