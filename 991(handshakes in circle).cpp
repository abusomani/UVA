#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll f[26],k;
	f[1] = 1;
	for(int i=2;i<=25;i++)
	{
		k = 0;
		for(int j=1;j<=i-2;j++)
		{
			k += f[j]*f[i-j-1];
		}
		k += 2*f[i-1];
		f[i] = k;
	}
	int n;
	int t  = 0;
	while(cin>>n)
	{
		if(t)printf("\n");t=1;
		 cout<<f[n]<<endl;
		 
	}	
}
