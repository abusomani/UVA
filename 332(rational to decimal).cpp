//	Algo to convert rational number to decimal number -     __
//  suppose we have 0.318181818.. so we can write it as  0.318  now we multiply it with 1000 and 10 and subtract them
//	318.1818.. - 3.1818.. = 315 divided by 1000 - 10  which will be our answer

#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b)	return gcd(b,a%b);
	else	return a;
}
int main()
{
	int k,a,b,g,n,d;
	string val;
	for(int s=1;1;s++)
	{
		cin>>k;
		if(k==-1)	break;
		cin>>val;
		d = val.size() - 2;
		n = 0;
		for(int i=2;i<val.size();i++)
		{
			n = n*10 + (int)val[i] - '0';
		}
		if(k!=0)
		{
			n = n - floor(n/pow(10,k));
			b = pow(10,d) - pow(10,d-k);
			g = gcd(n,b);		n/=g;		b/=g;
			printf("Case %d: %d/%d\n",s,n,b);
		}
		else
		{
			b = pow(10,d);
			g = gcd(n,b);		n/=g;		b/=g;
			printf("Case %d: %d/%d\n",s,n,b);
		}
	}
}
