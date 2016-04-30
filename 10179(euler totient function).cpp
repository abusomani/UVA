	//		programm for euler totient function

#include<bits/stdc++.h>
using  namespace std;
#define M 100

bool mark[M];
vector<int> prime;
vector<int> prime_div;

void markmultiples(int n,int k)
{
	for(int i=k+k;i<=n;i+=k)
		mark[i] = 1;
}
void sieve(int n)
{
	memset(&mark,0,sizeof(mark));
	markmultiples(n,2);
	prime.push_back(2);
	for(int i=3;i<=n;i+=2)
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
	int i = 0,k;
	while(n != 1)
	{
		k = 0;
		while(n%prime[i] == 0)
		{
			n /= prime[i];
			k++;
		}
		if(k>0)		prime_div.push_back(prime[i]);
		i++;
		if(i>prime.size()-1)		{	prime_div.push_back(n);		break;	}
	}
}
int main()
{
	sieve(M);
	int n , keep;
	while(cin>>n)
	{
		if(!n)	break;
		factor(n);
		for(int i=0;i<prime_div.size();i++)
		{
			n = n - n/prime_div[i];
		}
		cout<<n<<endl;
		prime_div.clear();
	}
}
