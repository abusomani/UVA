#include<bits/stdc++.h>
#define M 10000
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
	int t,n,p,x;
	int save,keep,mx;
	cin>>t;
	while(t--)
	{
		cin>>n;
		mx = 0;
	//	cout<<sch(n,0,prime.size()-1);
		
		for(int i=prime.size()-1;i>=0;i--)
		{
			x = prime[i];
			p = n/x;
			
			if(p!=0 && n> p*x && n<(p+1)*x)
			{
				save = n-p*x;
				//cout<<x<<"  "<<save<<endl;
				if(save > mx)
				{
					mx = save;
					keep = x;
				}	
				else
					break;
			}
		}
		cout<<keep<<endl;
	}
}
