/*
	main thing of question is that -  for given range we will generate upto sqrt(n)  which will cover all
	composite number upto n but not primes > sqrt(n)  so if a number is not divisible by any number in prime list
	so it is a prime number and should be printed as it is.
*/   

#include<bits/stdc++.h>
#define M 47000

using namespace std;
bool mark[M];
vector<int> prime;
void markmultiples(int n,int k)
{
	for(int i=k+k;i<=n;i+=k)
		mark[i] = 1;
}
void sieve(long n)
{
	memset(&mark,0,sizeof(mark));
	prime.push_back(2);
	for(int i=3;i<=n;i+=2)
	{
		if(!mark[i])
		{
			mark[i] = 1;
			prime.push_back(i);
			markmultiples(n,i);
		}
	}
}
void factorize(int n)
{
	int i = 0;
	bool flag = 1;
	while(n!=1)
	{
		while(n % prime[i] == 0)
		{
			n /= prime[i];
			if(flag)	
				cout<<prime[i],		flag = 0;
			else
				cout<<" x "<<prime[i];
		}
		i++;
		if(i>prime.size()-1)					// 		if number itself is a prime
		{	cout<<n;	break;	}
	}
	cout<<endl;
}
int main()
{
	long n;
	sieve(M);
	while(cin>>n)
	{
		if(n==0)	break;
		if(n<0)
		{
			printf("%ld = -1 x ",n);
			n = -n;
		}
		else
		{
			printf("%ld = ",n);
		}
		factorize(n);
	}
}
