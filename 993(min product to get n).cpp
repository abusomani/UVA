// 	here we need to get min product to get n so will factorize it from 9 to 2 and then print them because
//	prime factor won't work here it will give 23 while we'll require 6 so will factorize same as prime but with 9-2

#include<bits/stdc++.h>
using namespace std;
int prime[] = {9,8,7,6,5,4,3,2};
void factor(int n)
{
	int k , i =0;
	int f[10] = {0};
	while(n!=1)
	{
		k = 0;
		while( n%prime[i] == 0)
		{
			n /= prime[i];
			k++;
		}
		f[prime[i]] = k;
		i++;
		if(i==8)		{	break;	 }
	}
	if(n!=1)
	{	cout<<"-1\n";	return;     }
	for(int i=2;i<10;i++)
	{
		for(int j=0;j<f[i];j++)
			cout<<i;
	}
	cout<<endl;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<=9)
		{	cout<<n<<endl;	continue;	}
		factor(n);
	}
}
