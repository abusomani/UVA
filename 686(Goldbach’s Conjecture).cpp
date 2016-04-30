//	Goldbach’s Conjecture - every even number can be shown in terms of two prime numbers

#include<bits/stdc++.h>
#define M 33000
using namespace std;
vector<int> prime;
bool mark[M];

void markmultiples(int n,int k)
{
	for(int i=k+k;i<n;i+=k)
		mark[i] = 0;
}
void sieve(int n)
{
	memset(&mark,1,sizeof(mark));
	mark[1] = 0;
	markmultiples(n,2);
	for(int i=3;i<n;i+=2)
	{
		if(mark[i] == 1)
		{
			markmultiples(n,i);
		}
	}
}

int main()
{
	sieve(M);
	int n;
	while(cin>>n)
	{
		if(!n)	break;
		int ct = 0;
		if(n==4)
		{	cout<<1<<endl;	continue;	}
		for(int i=2;i<=n/2;i++)
		{
			if(mark[i] && mark[n-i])
			{
				ct++;
			}
		}
		cout<<ct<<endl;
	}
}
