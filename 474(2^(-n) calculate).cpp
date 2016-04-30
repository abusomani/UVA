#include<bits/stdc++.h>
#define M 1000004
using namespace std;
typedef pair<double,int> ii;
int main()
{
	double val = 0.1;		int x = 1;
	int p = 1; 
	int n;
	vector<ii> v;
	for(int i=1;i<M;i++)
	{
		val = val*2;
		if(val>=1)
		{	val /= 10;		p++;	}
//		cout<<val<<"  "<<p<<endl;
		v.push_back(ii(1.0/val , -p));
	}
	while(cin>>n)
	{
		printf("2^-%d = %.3fe%d\n",n,v[n-1].first,v[n-1].second);
	}
}
