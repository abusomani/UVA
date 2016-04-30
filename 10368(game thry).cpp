/*	game theory question here two player A,B are playing , the have two number each number they subtract a multiple of small
	number from big number and who can't subtract , lose . now at each state we need to consider only next state as b%a,b and
	b+b%a,b (if possible) beacuse other state will same as them so at last if number of step even, A win otherwise B win.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
map<ii,int> ans;
int c,k1,k2;
int solve(ll a,ll b,int ct)
{
	if(a<b)		swap(a,b);
	if(ans.count(ii(a,b)) == 1)
		return ans[ii(a,b)];
	cout<<a<<"  "<<b<<endl;
	k1 = k2 = 0;
	if(a%b == 0)	
	{
		if(ct&1)	return  1;
		else		return -1;
	}
	else		
	{
		k1 = solve(b,a%b,ct+1);
		if(a%b + b != a)
		{	k2 = solve(b,b + a%b,ct+1);	}
		
		if(ct&1)	
		{
			if(k1 == 1 || k2 == 1)
			{	ans[ii(a,b)] = 1;		return 1;	}
		}
		else
		{
			if(k1 == -1 || k2 == -1)
			{	ans[ii(a,b)] = -1;		return -1;	}
		}
	}
}
int main()
{
	ll a,b;
	while(cin>>a>>b && a && b)
	{
		int ct = solve(a,b,1);
		if(ct == 1)		{		printf("Stan wins");		}
		else			{		printf("Ollie wins");		}
		cout<<endl;
		ans.clear();
	}
}
