#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll trunc(ll n,ll k)
{
	int dig = 0;
	ll keep = n;
	while(n>0)
	{
		dig++;
		n /= 10;
	}
	k = dig - k;
	if(k>0)
	while(k--)
	{
		keep /= 10;
	}
	return keep;
}
int main()
{
	ll t,k;
	ll n,val;
	set<ll> st;
	cin>>t;
	while(t--)
	{
		cin>>k>>n;
		val = n;
		while(1)
		{
			n = n*n;
			n = trunc(n,k);
			val = max(val,n);	
			if(st.count(n) == 1)
				break;
			else
				st.insert(n);
		}	
		cout<<val<<endl;
		st.clear();
	}
}
