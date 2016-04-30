//		http://pavelsimo.blogspot.in/2012/06/uva-10680-lcm.html			<-  Best source
/*
		lcm(a,b)=|a·b| / gcd(a,b)
Another way to define the LCM between a and b is from their prime factorization.
For each prime factor of a and b we take the maximum exponent.

lcm(a,b)=  multiply for all primes ( prime ^ ( max ( exp_a,exp_b )) )     here exp_* is power of prime in a and b 
for 12 16  ,  12 = 2^2 3 	& 	 16 = 2^4   lcm = 2^(max(2,4)) * 3^(max(0,1)) = 16*3 = 48
*/

#include<bits/stdc++.h>
#define M 1000256
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
	prime.push_back(2);
	for(int i=3;i<n;i+=2)
	{
		if(mark[i] == 1)
		{
			prime.push_back(i);
			markmultiples(n,i);
		}
	}
}

int main()
{
	sieve(M);
	swap(prime[1],prime[2]);		//  3 and 5 are swapped and lcm count starts from 3 onwards
	int n,lcm;
	int power_2,power_5,power_p;
	while(cin>>n)
	{
		if(!n)		break;
		power_2 = power_5 = 0;
		for(int i=2;i<=n;i*=2)	power_2++;
		for(int i=5;i<=n;i*=5)	power_5++;
		
		lcm = 1;
		for(int i=0;i<(power_2 - power_5);i++)		// power_5 times pair of 2 and 5 will make zeros so don't count
			lcm = (lcm*2)%10;
			
	//	cout<<lcm<<endl;
		for(int i=2;i<prime.size();i++)
		{
			if(prime[i]>n)		break;
			for(long long j = prime[i] ; j<=n ; j*=prime[i])      
				lcm = (lcm*prime[i])%10;
		}
		cout<<lcm<<endl;
	}
}
