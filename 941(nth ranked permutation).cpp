//	finding nth ranked permutation of a string

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll fact(int n)
{
	ll ans = 1;
	for(int i=1;i<=n;i++)
	{
		ans *= i;
	}
	return ans;
}
int main()
{	
	int t;
	cin>>t;	
	ll n,mid,f;	string str;
	while(t--)
	{
		cin>>str>>n;
		int l = str.length();
		sort(str.begin(),str.end());
		while(l!=0)
		{
			f = fact(l-1);
			mid = n / f;
			cout<<str[mid];
			n = n%f;	l--;
			str.erase(str.begin()+mid);
		}
		cout<<endl;
	}
}
