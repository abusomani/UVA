//   Modified sieve to get sum of distinct divisors

#include<bits/stdc++.h>
#define M 5000003
using namespace std;
int mark[M];

void markmultiples(int n,int k)
{
	for(int i=k+k;i<n;i+=k)
		mark[i] += k;
}
void sieve(int n)
{
	memset(&mark,0,sizeof(mark));
	for(int i=2;i<n;i++)
	{
		if(mark[i] == 0)
		{
			markmultiples(n,i);
		}
	}
}


int main()
{
	sieve(M);
	int sum = 0,a,b;
	int ans[M];
	ans[1] = 0;
	for(int i=2;i<M;i++)
		ans[i] = ans[i-1] + ( mark[i] == 0 ? 1 : mark[mark[i]]==0) ;
	//	cout<<i<<"  :  "<<ans[i]<<endl;

	while(1)
	{
		cin>>a;
		if(a==0)	break;		cin>>b;
		cout<<ans[b]-ans[a-1]<<endl;
	}
}
