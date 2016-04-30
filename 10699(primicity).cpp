#include<bits/stdc++.h>
#define M 1000003
using namespace std;
vector<int> prime;
int mark[M];

void markmultiples(int n,int k)
{
	for(int i=k;i<n;i+=k)
		mark[i]++;
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
int main()
{
	sieve(M);
	int n;
	while(cin>>n)
	{
		if(!n)	break;
		if(n%2 == 0)
			cout<<n<<" : "<<mark[n]+1<<endl;
		else
			cout<<n<<" : "<<mark[n]<<endl;
	}
}
