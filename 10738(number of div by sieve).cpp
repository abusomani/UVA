//  UVA  10738
//	modified sieve to get number of distinct prime divisors and ignoring those number which are having power more
//	than one ( in 17 line this restriction is there )

#include<bits/stdc++.h>
#define MX 1000003 
using namespace std;
int mark[MX];

void markmultiples(int n,int k)
{
	for(int i=k;i<n;i+=k)
	{
		if(mark[i] != -1)
		{
			mark[i]++;	
			if((i % (k*k)) == 0)			//   ignoring those which came more than one . 
				mark[i] = -1;
		}
	}
}
void sieve(int n)
{
	memset(&mark,0,sizeof(mark));
	for(int i=2;i<n;i++)
	{
		if(mark[i] == 0)
		{
			markmultiples(n,i);
		}
	}
}

int main()
{
	sieve(MX);
	int mu[MX],M[MX];
	int sum = 1,n;
	mu[1] = M[1] = 1;
	for(int i=2;i<MX;i++)
	{
		if(mark[i] == -1)
			mu[i] = 0;
		else
		    mu[i] = ( (mark[i]%2) ? -1 : 1);
		sum += mu[i];
		M[i] = sum;
	}
	while(cin>>n)
	{
		if(!n)	break;
		printf("%8d%8d%8d\n",n,mu[n],M[n]);												
	}										
}
