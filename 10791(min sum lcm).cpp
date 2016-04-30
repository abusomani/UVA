#include<bits/stdc++.h>
#define M 1000
using namespace std;
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

int calculate(int n)		
{
	int i = 0,k = 0,sum,gsum;
	int keep = n;					
	while(n != 1)
	{
		k = 0;
		int val = 1;
		while(n%prime[i] == 0)
		{
			n /= prime[i];
			k++;
			val *= prime[i];
			gsum = prime[i];
		}
		if(k>0)		
		{
			sum += val;
		}
    	i++;
    	if(i>prime.size()-1  && n!=1)	{  sum += n;	break; 	}
	}
	if(sum == 0)		return n+1;
	if(sum == keep)
	{
		if(k%2==0)
			return 2*pow(gsum,k/2);
		else
			return pow(gsum,k/2) + pow(gsum,k/2+1) ; 
	}
	else
		return sum;
}

int main()
{
	sieve(M);
	int n;
	for(int j=1;1;j++)
	{
		cin>>n;
		if(!n)		break;
		if(n==1)			{	printf("Case %d: 2\n",j);				continue;	}
		if(n==2147483647)	{	printf("Case %d: 2147483648\n",j);		continue;	}
		printf("Case %d: %d\n",j,calculate(n));
	}
}
