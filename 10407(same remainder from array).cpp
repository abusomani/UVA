//	For negative numbers (-n)%k = k - n%k  as (-144)%5 = 5 - 144%5 = 5-4 = 1;
//	here we need to find a number such that a[i]%m should be same for all numbers 
//	for this thing we will get the gcd of increment of all number from previous number and that will be our ans

#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b)		return gcd(b,a%b);
	else		return a;
}
int abs(int x)
{
	if(x<0)		return -x;
	else		return x;
}
bool cmp(const int &a,const int &b)
{
	return abs(a)-abs(b);
}
int main()
{
	int n;
//	int a = -22;		cout<<3-(-a)%3<<endl;
	vector<int> v;
	while(cin>>n)	
	{
		if(!n)		break;
		v.push_back(n);
		while(cin>>n)
		{
			if(!n)		break;
			v.push_back(n);
		}
		sort(v.begin(),v.end(),cmp);
		for(int i=1;i<v.size();i++)
		{
			v[i-1] = abs(v[i] - v[i-1]);
		}
		v.erase(v.end()-1);
		int g = v[0];
		for(int i=1;i<v.size();i++)
			g = gcd(g,v[i]);
		cout<<g<<endl;
		v.clear();
	}
}
