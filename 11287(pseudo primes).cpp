//uva 11287

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll base,ll exp,ll mod)
{
	ll res = 1;
	base = base%mod;
	while(exp>0)
	{
		if(exp & 1)
		{
			res = (res * base)%mod;
		}
		exp = exp>>1;
		base = (base*base)%mod;
	}
	return res%mod;
}
#define M 46800
bool arr[M];
vector<int> prime;
void markMultiples(int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; 
        ++i;
    }
}
void sieve(int n)
{
	int k = 0;
    if (n >= 2)
    {
        memset(arr, 0, sizeof(arr));
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                prime.push_back(i+1);
                markMultiples(i+1, n);
            }
        }
    }
}
bool isprime(ll x)
{
	if(x<prime[prime.size()-1])
		return binary_search(prime.begin(),prime.end(),x);
		
	for(int i=0;i<prime.size();i++)
	{
		if(x%prime[i] == 0)
			return 0;
	}
	return 1;
}
int main()
{
	sieve(M);
	ll p,a;
	while(cin>>p>>a)
	{
		if(p==0 && a==0)	break;
		ll k = pow(a,p,p);
		if(k==a  &&  !isprime(p))
			cout<<"yes";
		else
			cout<<"no";
		cout<<endl;
	}
}
