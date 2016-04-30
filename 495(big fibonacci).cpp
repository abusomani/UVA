#include<bits/stdc++.h>
using namespace std;
string add(string a, string b)			//	Adding two big numbers by string
{
	int i = b.length()-1;
	int j = a.length()-1;
	string c = "";		int sum , carry = 0;
	while(1)
	{
		if(j>=0)
		{
			sum = b[i--]-'0' + a[j--]-'0' + carry;
		}
		else
			sum = b[i--]-'0' + carry;
			
		carry = sum/10;
		c += sum%10 + '0';
		if(i < 0)								//   condition on  i because we know b>a
			break;
	}
	if(carry > 0)
		c += carry + '0';
	reverse(c.begin(),c.end());
	return c;
}
int main()
{
	int n;
	string a,b,c;
	string fib[5001];
	a = "0";	b = "1";
	for(int i=2;i<=5000;i++)
	{
		c = add(a,b);
		a = b;	
		b = c;
		fib[i] = c;
	}
	while(cin>>n)
	{
		if(n<2)
			cout<<"The Fibonacci number for "<<n<<" is "<<n<<endl;
		else
		{
			cout<<"The Fibonacci number for "<<n<<" is "<<fib[n]<<endl;
		}
	}
}
