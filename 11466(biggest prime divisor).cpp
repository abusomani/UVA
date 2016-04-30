#include<bits/stdc++.h>
#define M 10001000
#define MAX 2147483647
using namespace std;
typedef long long ll;
bool arr[M];
vector<int> prime;
void markMultiples(int a, int n)
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
                markMultiples(i+1, n);
            }
        }
    }
}
ll factor(ll n)
{
	int i = 0 , k = 0;
	ll keep = n,lastprime,save;
	bool flag = 0;		bool first = 0;
	while(n != 1)
	{
		while(n%prime[i] == 0)
		{
			n /= prime[i];
			k++;
			if(!first)		   {   save = prime[i];		first = 1;	}
		}
		i++;
		if(k>0)				   {	lastprime = prime[i-1];		}
		if(i>prime.size()-1)   {	lastprime = n;	 flag = 1;   break; 	}
	}
	if(flag)
	{
		if(keep == n)		return -1;
		else				return lastprime;
	}
	if(lastprime == save)	
		return -1;
	else
		return lastprime;
}
ll mabs(ll n)
{
	if(n<0)
		return -n;
	else
		return n;
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	sieve(M);
	ll n;
	while(cin>>n)
	{
		if(n==0)		break;
		if(n<0)		
		{	n = -n;			}
		if(n==1)	{	cout<<-1<<endl;		continue;	}
		cout<<factor(n)<<endl;
	}
}
