/*
	here we need to get total divisorrs of a factorial so we will loop throough all n's and keep track of power of 
	primes and then ans = (ct[p_2]+1 ) * (ct[p_3]+1) * ( ct[p_5]+1 ) ...
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
#define mset(x,val)	 memset(&x,val,sizeof(x))
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long ll;
typedef unsigned long long ull;


#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;


#define M 1007
vector<int> prime;
bool mark[M+1];

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

int ct[M+5];

int div(int n)		
{
	int i = 0;
	while(n != 1)
	{
		while(n%prime[i] == 0)
		{
			n /= prime[i];
			ct[prime[i]]++;
		//	cout<<ct[prime[i]]<<endl;
		}
    	i++;
    	if(i>prime.size()-1)	break;
	}
}

int main()
{
	sieve(M);
	
	/*	div(12);
		for(int i=0;i<10;i++)
		{
			cout<<ct[prime[i]]<<endl;
		}*/
	int t,n,i,k;
	ll mulfact;
	string str;
	s(t);
	for(int j=1;j<=t;j++)
	{
		memset(&ct,0,sizeof(ct));
		n =	0;
		cin>>str;
		for(i=0;i<str.length();i++)
		{
			if(str[i] != '!')
				n = n*10 + str[i]-'0';
			else
				break;
		}
		k = str.length() - i;
		
		for(int i=n;i>0;i-=k)
		{
			div(i);	
		}
		
		mulfact = 1LL;
		for(int i=0;prime[i]<=n;i++)
		{
			if(ct[prime[i]])
				mulfact *= ct[prime[i]]+1;
			//	cout<<prime[i]<<" "<<ct[prime[i]]<<endl;
			if(mulfact > 1e18)
			{	printf("Case %d: Infinity",j);		goto end;	}
		}
	
		printf("Case %d: %lld",j,(mulfact));
		end:
		nl;
	}

}
