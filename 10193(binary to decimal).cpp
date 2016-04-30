#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int gcd(int a,int b)
{
	if(b)
		return gcd(b,a%b);
	else
		return a;
}
int tobin(string str)
{
	int l =str.length();
	int k = 1,n=0;
	for(int i=l-1;i>=0;i--)
	{
		if(str[i]=='1')	
			n += k; 
		k = k*2;
	}
	return n;
}
int main()
{
	int t,a,b;
	cin>>t;
	string str1,str2;
	for(int j=1;j<=t;j++)
	{
		cin>>str1>>str2;
		a = tobin(str1);		b = tobin(str2);
		if(gcd(a,b)==1)
			printf("Pair #%d: Love is not all you need!\n",j);
		else	
			printf("Pair #%d: All you need is love!\n",j);
	}
}
