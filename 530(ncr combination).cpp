#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ncr(ll n,ll r)
{
	ll ans = 1;
	if(n-r < r)	  r = n-r;	
	for(int i=0;i<r;i++)
	{
		ans = (ans*(n-i))/(i+1);
	}
	return ans;
} 
int main()
{
	ll n,r;
	while(1)
	{
		cin>>n>>r;
		if(n==0 && r==0)	break;
		cout<<ncr(n,r)<<endl;
	}
}
