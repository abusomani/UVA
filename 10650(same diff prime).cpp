#include<bits/stdc++.h>
#define M 330000
using namespace std;
typedef pair<int,int> ii;
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
int main()
{
	sieve(M);
	int a,b,i,lasti,j,lo,hi;
	int dif,lastdif;
	while(cin>>a>>b)
	{
		if(a==0 && b==0)		break;
		lo = lower_bound(prime.begin(),prime.end(),a) - prime.begin();
		hi = upper_bound(prime.begin(),prime.end(),b) - prime.begin();
		
		
		lastdif = prime[lo+1] - prime[lo];
		lasti = lo;
		for(i=lo+1;i<=hi;i++)
		{
			dif = prime[i] - prime[i-1];
			if(dif == lastdif)
			;
			else
			{
				if(i-lasti > 2)
				{
					for(j=lasti;j<i;j++)
						cout<<prime[j]<<" ";
					cout<<endl;
				}
				lasti = i-1;
			
			}
			lastdif = dif;
		//	cout<<dif<<"  "<<lastdif<<"  "<<lasti<<"  "<<i<<endl;
		}
	}	
}
