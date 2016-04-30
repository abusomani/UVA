#include<bits/stdc++.h>
#define M 33000
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

int sl(int n)
{
	int sum = 0;
	while(n>0)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}
int factorize(int n)		
{
	int i = 0,k;
	int keep = n;
	int sum = 0;
	while(n != 1)
	{
		k = 0;
		while(n%prime[i] == 0)
		{
			n /= prime[i];
			sum += sl(prime[i]);
	//		cout<<prime[i]<<endl;
			k++;
		}
    	i++;
    	if(i>prime.size()-1)
			if(sum==0)	return -3;								//  number itself is prime but outside sieve
			else		{  sum += sl(n);	break;	}		
    	
	}
	if(prime[i-1] == keep)				//	number itself is prime and got by sieve
		return -2;
	if( sum == sl(keep) )				//  got smith number
		return 1;
	else
		return -1;
}
int main()
{
	sieve(M);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		n++;
		while(factorize(n) < 0)
		{
			n++;
		}
		cout<<n<<endl;
	}
}
