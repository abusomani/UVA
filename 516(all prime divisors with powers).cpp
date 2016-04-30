#include<bits/stdc++.h>
#define M 33000
using namespace std;
vector<int> prime;
typedef pair<int,int> ii;
bool mark[M];

void markmultiples(int n,int k)
{
	for(int i=k;i<n;i+=k)
		mark[i] = 1;
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
void factorization(int n)		
{
	int i = 0,k;
	vector<ii> divisors;				//   comment off to get prime divisors 
	while(n != 1)
	{
		k = 0;
		while(n%prime[i] == 0)
		{
			n /= prime[i];
			k++;
		}
		if(k>0)	divisors.push_back(ii(prime[i],k));
    	i++;
	}
	for(int i=divisors.size()-1;i>0;i--)
		cout<<divisors[i].first<<" "<<divisors[i].second<<" ";
	cout<<divisors[i].first<<" "<<divisors[i].second;
	cout<<endl;
}


int main()
{
	sieve(M);
	string line;
	int multy,exp,base;
	int num;	
//	factorization(30030);
	while(getline(cin,line))
    {
       if(line=="0") break;
       multy=1;
       istringstream ss(line);
       while(ss>>base)
       {
           ss>>exp;
           multy*=pow(base,exp);
       }
       num = multy-1;
	//	cout<<num<<endl;
		factorization(num);
	}
}
