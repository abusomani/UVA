//		uva 948

#include<bits/stdc++.h>
#define M 42
using namespace std;
int fib[M+2];
void precalculate()
{
	fib[1] = 1;		fib[2] = 2;
	for(int i=3;i<=M;i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
}
string tofibbase(int n)
{
	string ans;		int save = n;
	int i;
	for(i=M;i>=1;i--)
	{
		if(n>=fib[i])
		{
			n -= fib[i];
		//	cout<<i<<"  "<<fib[i]<<"  "<<n<<endl;
			ans = "1";
			break;
		}
	}
	i--;
	for(;i>=1;i--)
	{
		if(n>=fib[i])
		{
			n -= fib[i];
		//	cout<<i<<"  "<<fib[i]<<"  "<<n<<endl;
			ans += '1';
		}
		else
			ans += '0';
	}		
	return ans;
}
int main()
{
	int t,n;
	precalculate();
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<n<<" = "<<tofibbase(n)<<" (fib)\n";
	}
}
