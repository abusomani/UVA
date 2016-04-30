//	under construction			this gives precise steps to change from one string to another

#include<bits/stdc++.h>
using namespace std;
#define M 25
int min(int a,int b,int c)
{
	return min(a,min(b,c));
}
string num(int i)
{
	string b="";
	b += (char)(i%10 +'0');
	if(i/10 == 0)
		return ("0" + b);
	return ( char(i/10 + '0') + b);
}
int main()
{
	int ed[M][M];
	string str1,str2;
	string ans,tmp;
	while(1)
	{
		ans = "";
		cin>>str1;
		if(str1 == "#")		break;
		cin>>str2;
		int m = str1.length();
		int n = str2.length();
		memset(&ed,0,sizeof(ed));
		
		for(int j=0;j<=m;j++)
			ed[j][0] = j;
			
		for(int i=0;i<=n;i++)
			ed[0][i] = i;
			
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(str1[i-1] != str2[j-1])
				{
					ed[i][j] = min( ed[i-1][j-1]+1 , ed[i-1][j]+1 , ed[i][j-1]+1 );
				} 
				else
					ed[i][j] = ed[i-1][j-1];
			}
		}
		/*
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<ed[i][j]<<"  ";
			}
			cout<<endl;
		}
		*/
		int i = m;
		int j = n;
		while(true)
		{
			tmp = "";
			if(i==0 and j==0)	break;
			if(str1[i-1] == str2[j-1])
			{	i--;	j--;	}
			else
			{
				//cout<<str1[i-1]<<"  "<<str2[j-1]<<endl;
				if(ed[i][j] == ed[i-1][j-1] + 1)
				{
					tmp += "C";		tmp += str2[j-1];	 tmp += num(i);
					ans.insert(0,tmp);
					i--;	j--;
				}
				else if(ed[i][j] == ed[i-1][j] + 1)
				{
					tmp += "D";		tmp += str1[i-1];	 tmp += num(i);
					ans.insert(0,tmp);
					i--;
				}	
				else
				{
					tmp += "I";		tmp += str2[j-1];	 tmp += num(i);		
					ans.insert(0,tmp);
					j--;
				}	
			}
		}
		ans += "E";
		cout<<ans<<endl;
	}
}
