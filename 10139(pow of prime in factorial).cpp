//The exponent of a prime p in n! is sigma(from 1 to log n_basep )   n/pow(p,k);
//	for ex power of 5 in 100!   =  100/5 + 100/25 

#include<bits/stdc++.h>
#define M 46400							// 		sqrt of the limit till you want factorization
using namespace std;

typedef pair<int,int> ii;
vector<int> prime;
bool mark[M];
vector<ii> divisors;

void markmultiples(int n,int k)
{
	for(int i=k+k;i<n;i+=k)				
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

void factor(int n)		
{
	int i = 0,k = 0;					
	while(n != 1)
	{
		k = 0;
		while(n%prime[i] == 0)
		{
			n /= prime[i];
			k++;
		}
    	if(k>0)					{		divisors.push_back(ii(prime[i],k));		}
    	if(i>=prime.size()-1)	{ 	 	divisors.push_back(ii(n,1));	break; 	}
    	i++;
	}
}

long long get_powers(long long n, long long p)
{
     long long res = 0;
    for (long long power = p ; power <= n ; power *= p)
        res += n/power;
    return res;
}

int main()
{
	int n,b,ct;
	bool divide;
	sieve(M);
	while(cin>>n>>b)
	{
		if(b==0)	{	printf("%d does not divide %d!\n",b,n);	continue;	}
		factor(b);
		divide = true;
		for(int i=0;i<divisors.size();i++)
		{
			if(divisors[i].second > get_powers(n,divisors[i].first))
			{	divide = false;		break;	}
		}
		if(divide)		{	printf("%d divides %d!",b,n);				}
		else			{	printf("%d does not divide %d!",b,n);		}
		divisors.clear();
		cout<<endl;
	}
}
