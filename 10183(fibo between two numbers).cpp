#include<bits/stdc++.h>
using namespace std;
#define M	485
string add(string a, string b)			//	Adding two big numbers by string		Assuming a>=b
{
	int i = b.length()-1;
	int j = a.length()-1;
	string c = "";		
	int sum , carry = 0;
	while(1)
	{
		if(j>=0)
		{
			sum = b[i--]-'0' + a[j--]-'0' + carry;
		}
		else
			sum = b[i--]-'0' + carry;
			
		carry = sum/10;
		c += sum%10 + '0';
		if(i < 0)								//   condition on  i because we know b>a
			break;
	}
	if(carry > 0)
		c += carry + '0';
	reverse(c.begin(),c.end());
	return c;
}
bool comp(string a,string b)
{
	if(a.length() > b.length())
		return 1;
	if(b.length() > a.length())
		return 0;
		
	return a>=b;
}
int main()
{
	int n;
	string a,b;
	
	string fib[M+5];
	fib[0] = "1";		fib[1] = "2";
	for(int i=2;i<=M;i++)
	{
		fib[i] = add(fib[i-2],fib[i-1]);
	}
	while(cin>>a>>b)
	{
		int ct = 0;
		if(a=="0" && b=="0")		break;
		for(int i=0;i<=M;i++)
		{
		//	cout<<fib[i]<<"  "<<a<<"  "<<b<<"  "<<comp(fib[i],a)<<"  "<<endl;
			if( comp(fib[i],a) && comp(b,fib[i]) )
				ct++;
			if(comp(fib[i],b))
				break;
		}
		cout<<ct<<endl;
	}
}
