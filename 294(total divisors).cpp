#include<bits/stdc++.h>
using namespace std;
#define M 33000
vector<int> prime;
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

int factoriztion(int n)		
{
	int i = 0,k;
	int total = 1;
//	vector<int> divisors;				//   comment off to get prime divisors 
	while(n != 1)
	{
		k = 0;
		while(n%prime[i] == 0)
		{
			n /= prime[i];
			k++;
		}
	//	if(k>0)	divisors.push_back(prime[i]);
		total *= (k+1);
    	i++;
    	if(i>prime.size()-1)	return 2;
	}
//	for(int i=0;i<divisors.size();i++)
//		cout<<divisors[i]<<endl;
	return total;
}

int main()
{
	sieve(M);
	long l,u,val;
	long t,k,maxi;
	cin>>t;
	while(t--)
	{
		cin>>l>>u;
		maxi = 0;
		for(long i=l;i<=u;i++)
		{
			k = factoriztion(i);
			if(k>maxi)
			{
				maxi = k ;
				val = i;
			}
		}
		printf("Between %ld and %ld, %ld has a maximum of %d divisors.\n",l,u,val,maxi);
	}
}
