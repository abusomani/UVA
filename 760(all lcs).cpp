//	uva 760    print all lcs   ( here done by backtracking so TLE )
#include<bits/stdc++.h>
#define M 500
using namespace std;
string str1,str2,tmp;
int L[M][M];
char* ptr[M][M];
vector<char> ans;
set<string> st;
void print_lcs(int i,int j)
{
	//cout<<i<<"  "<<j<<endl;
	if(i==0 || j==0 || L[i][j]==0)
	{
		tmp = "";
		for(int k=ans.size()-1;k>=0;k--)		tmp += ans[k];
		st.insert(tmp);
		return;	
	}
	if(str1[i-1] == str2[j-1])
	{
		ans.push_back(str1[i-1]);
		print_lcs(i-1,j-1);
		ans.erase(ans.end()-1);
	}
	else
	{
		if(L[i][j] == L[i-1][j])
			print_lcs(i-1,j);
		if(L[i][j] == L[i][j-1])
			print_lcs(i,j-1);	
	}
}
int main()
{
	str1 = str2 = "";
	int i = 0,idx;
	char lcs[M];
	while(cin>>str1>>str2)
	{		
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

		int res = L[m][n];
		ans.clear();
		st.clear();
		print_lcs(m,n);
		set<string>:: iterator p = st.begin();
		while(p != st.end())
		{
			cout<<*p<<endl;
			p++;
		}
		cout<<endl;
	}
} 
