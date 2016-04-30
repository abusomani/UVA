#include<bits/stdc++.h>
#define M 1010
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
	prime.push_back(1);
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
	int n,C,pos,i;
	int low,high;
	vector<int>:: iterator p;
	while(cin>>n>>C)
	{
		i = lower_bound(prime.begin(),prime.end(),n) - prime.begin() ;
		while(i >= prime.size() || prime[i] > n) i--;
 
        i++; // increment index to represent size
        int c = (i % 2)? C * 2 - 1 : C * 2; // get size of printed list
 
        int low = (i - c) > 0? (i - c) / 2 : 0; // calc start index
        int high = (i - c) > 0? low + c : i; 
        
        cout<<n<<" "<<C<<": ";
		for(int j=low;j<high;j++)
			cout<<prime[j]<<" ";
		cout<<endl;
	}
}
