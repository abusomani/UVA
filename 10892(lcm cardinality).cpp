#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b)	return gcd(b,a%b);
	else	return a;
}
int lcm(int a,int b)
{
	if(a>b)		swap(a,b);
	return a*(b/gcd(a,b));
}
int main()
{
	int n;
	int ct = 0;
	vector<int> div;
	while(1)
	{
		cin>>n;		if(!n)	break;
		ct = 0;
		int lim = sqrt(n);
		for(int i=1;i<=lim;i++)
		{
			if(n%i == 0)
			{
				if(i != n/i)
					div.push_back(i),
					div.push_back(n/i);
				else
					div.push_back(i);
			}
		}
		for(int i=0;i<div.size();i++)
		{
			for(int j=i;j<div.size();j++)
			{
				if(lcm(div[i],div[j]) == n)
					ct++;
			}
		}
	
		cout<<n<<" "<<ct<<endl;
		div.clear();
	}
}
