//	question based on preprocessing here all number who have single prime divisors are asked so we stored all powers
//	of prime from 2 to 10^6 which are less than MAX limit and then answer the queries from them


#include<bits/stdc++.h>
#define M 1000003
#define MAX 1000000000000
using namespace std;
typedef long long ll;
vector<int> prime;
vector<ll> almost;
bool mark[M];

void markmultiples(int n,int k)
{
	for(int i=k;i<n;i+=k)
		mark[i] = 1;
}
void sieve(int n)
{
	prime.push_back(2);
	memset(&mark,0,sizeof(mark));
	for(int i=3;i<n;i+=2)
	{
		if(mark[i] == 0)
		{
			prime.push_back(i);
			markmultiples(n,i);
		}
	}
}
void preprocess()
{
	ll k;
	for(int i=0;i<prime.size();i++)
	{
		k = prime[i];
		while(k<MAX)
		{
			k = k*prime[i];
			almost.push_back(k);
		}
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	sieve(M);
	preprocess();
	sort(almost.begin(),almost.end());
//	for(int i=0;i<30;i++)
//		cout<<almost[i]<<endl;
	int t;
	ll a,b;
	ll ct;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		ct = lower_bound(almost.begin(),almost.end(),b) - lower_bound(almost.begin(),almost.end(),a);
		cout<<ct<<endl;
	}
}
