/*	here we need to get max power of any number( not prime ) in n!		which will be min of power of primes it contains
	as suppose we want power in 40! 	now 
	max_p (2) = 40/2 + 40/4 ...= 38  and max_p (3) = 40/3 + 40/9 + 40/27 = 18
	for 6 (2 3) -> ans = min(38,18) = 18	for 12( 2^2 3) -> ans = min(19,18) = 18
	for 24 (2^3 3) -> ans = min(38/3 , 18) = 12 
*/

#include<bits/stdc++.h>
#define M	5000							// 		sqrt of the limit till you want factorization if it is big 
#define MAX 2147483647
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



int power_in_fact(int n,int p)
{
	int res = 0;
	for(int i=p;i<=n;i*=p)
	{
		res += n/i;
	}
	return res;
}
int main()
{
	sieve(M);
	int t,m,n,k1;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>m>>n;
		int k = MAX;
		factor(m);
		for(int i=0;i<divisors.size();i++)
		{
			k1 = power_in_fact(n,divisors[i].first);
			k = min(k , k1/divisors[i].second);
		}
		cout<<"Case "<<j<<":"<<endl;
		if(k!=0)
			cout<<k<<endl;
		else
			cout<<"Impossible to divide\n";	
		divisors.clear();
	}
}
