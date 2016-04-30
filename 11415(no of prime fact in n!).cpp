#include<bits/stdc++.h>
#define M 10000007
using namespace std;
bool mark[M+2];
int nfactor[M+2];
void markmultiples(int n,int k)
{
	int keep;
	for(int i=k;i<=n;i+=k)
	{
		mark[i] = 1;
		keep = i;
		while(keep % k == 0)	
		{
			keep /= k ;
			nfactor[i]++;
		}
	}
} 
void sieve(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(mark[i] == 0)
		{
			markmultiples(n,i);
		}
	}
}
int main()
{
	int t,n;
	sieve(M);
	for(int i=2;i<M;i++)
	{
		nfactor[i] += nfactor[i-1];
		//cout<<i<<" : "<<nfactor[i]<<endl;
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		int pos = lower_bound(nfactor,nfactor+M,n) - nfactor ; 
		if(nfactor[pos] > n)
			pos--;
		cout<<(pos+1)<<endl;
	}
}
