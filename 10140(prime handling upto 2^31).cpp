//	Here the range of primes which we need to handle is very high ( upto 2147483647 ) so we will generate prime 
//	upto sqrt(n) and then in range lo to high we will mark with the help of these primes and operate  

#include<bits/stdc++.h>
#define M 46800
#define MAX_RANGE 1000502
#define MAX 2147483647
using namespace std;
bool arr[M];
bool mark[MAX_RANGE];
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
void markinrange(int a,int b)
{
	int upto = ceil(sqrt(b));	
	memset(&mark,0,sizeof(mark));
	int k,m;
	long long i;
	m = 0;
	while(1)
	{
		k = prime[m];
		for(i=a;i<=b;i++)
		{
			if(i%k==0)
			{
				if(i>k)		mark[i-a] = 1;	
				break;
			}
		}
		i += k;
		for(;i<=b;i+=k )				
		{
 			mark[i-a] = 1;
		}
		m++;
	//  cout<<prime[m]<<endl;
		if(prime[m]>upto)	break;
	}
}								
int main()
{
	int a,b,u,v,w,x,last,mindif,maxdif;
	long long i;
	sieve(M);
	while(cin>>a>>b)
	{
		if(a==1) a++;
		markinrange(a,b);
		mindif = MAX;	maxdif = 0;
	/*	for(i=a;i<=b;i++)
		{
			cout<<i<<"  "<<mark[i-a]<<endl;
		}*/
		for(i=a;i<=b;i++)
		{
			if(!mark[i-a])
			{
				last = i;
				break;
			}
		}
		i++;
		for(;i<=b;i++)
		{
			if(!mark[i-a])
			{
				if(mindif > i-last)
				{
					mindif = i-last;
					u = last;	v = i;
				}
				if(maxdif < i-last)
				{
					maxdif = i-last;
					w = last;	x = i;
				}
				last = i;
			}
		}
		if(mindif == MAX)
			cout<<"There are no adjacent primes.\n";
		else
			printf("%d,%d are closest, %d,%d are most distant.\n",u,v,w,x);
	}
}
