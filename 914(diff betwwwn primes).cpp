#include<bits/stdc++.h>
#define M 1000000

using namespace std;
vector<int> prime;
bool arr[M];
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; 
        ++i;
    }
}
void sieve(int n)
{
	int k = 0;
    if (n >= 2)
    {
        memset(arr, 0, sizeof(arr));
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
            	prime.push_back(i+1);
                markMultiples(arr, i+1, n);
            }
        }
    }
}

int main()
{
	sieve(M);
	int t,a,b,lo,hi,dif,maxv,keep;
	map<int,int> mp;
	map<int,int>:: iterator p;
	cin>>t;
	int flag = 0;
	while(t--)
	{
		cin>>a>>b;
		lo = lower_bound(prime.begin(),prime.end(),a) - prime.begin();
		hi = lower_bound(prime.begin(),prime.end(),b) - prime.begin();
		
		
		if(prime[hi] > b)
			hi--;
		
		for(int i=lo+1;i<=hi;i++)
		{
			dif = prime[i] - prime[i-1];
			if(mp.count(dif) == 0)
				mp[dif] = 1;
			else
				mp[dif]++;
		}
		p = mp.begin();
		maxv = 0;
		keep =0;
		while(p!=mp.end())
		{
			if(maxv < p->second)
			{
				maxv = p->second;
				keep = p->first;
			}
			p++;
		}
		p = mp.begin();
		flag = 0;
		while(p!=mp.end())
		{
			if(maxv == p->second)
				flag++;
			p++;
		}
		if(flag > 1 || keep ==0)
			cout<<"No jumping champion\n";
		else
			printf("The jumping champion is %d\n",keep);
		mp.clear();
	}
}
