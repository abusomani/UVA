#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dig(ll v)
{
	int ct = 0;
	while(v)
	{
		v/=10;
		ct++;
	}
	return ct;
}
void print(ll v)
{
	int s = 7 - dig(v);
	for(int i=0;i<s;i++)
		cout<<"0";
	if(v!=0)	cout<<v<<endl;
	else		cout<<endl;
}
int main()
{
	string str;
	long double x = (long double)10000000/864000 ; 
	ll v;
	int h,m,d,c;
	while(cin>>str)
	{
		v = ((str[0]-'0')*10 + (str[1]-'0'))*360000 + ((str[2]-'0')*10 + (str[3]-'0'))*6000 + ((str[4]-'0')*10 + (str[5]-'0'))*100 + ((str[6]-'0')*10 + (str[7]-'0'));
		print(v*x/10);
	}
}
