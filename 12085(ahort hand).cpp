#include<bits/stdc++.h>
using namespace std;
string rev(int &a)
{
	string num = "";
	while(a)
	{
		num += char(a%10+'0');
		a /= 10;
	}	
	int l = num.length();
	for(int i=0;i<l/2;i++)
	{
		swap(num[i],num[l-i-1]);
	}
	return num;
}
void print(int a,int b)
{
	int save = a,i;
	string x = rev(a);	string y = rev(b);
	int l = x.length();
	for(i=0;i<l;i++)
	{
		if(x[i]!=y[i])
			break;
	}
	cout<<"0"<<x<<"-"<<y.substr(i)<<endl;
}
int main()
{
	int n,i;
	int a[100002],pre;
	bool firstime = 1;
	bool conti;
	for(int j=1;1;j++)
	{
		cin>>n;		if(!n)	break;
		for(i=0;i<n;i++)
			cin>>a[i];
		
		firstime = 1;
		conti = 0;
		cout<<"Case "<<j<<":"<<endl;

		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1]+1)
			{
				if(firstime==1)
				{
					firstime = 0;
					pre = a[i-1];
				}
				conti=1;
			}
			else
			{
				if(conti==0)
				{
					cout<<"0"<<a[i-1]<<endl;
				}
				else
				{
					print(pre,a[i-1]);
				}
				firstime = 1;
				conti = 0;
			}
		}
		if(conti==0)
		{
			cout<<"0"<<a[i-1]<<endl;
		}
		else
		{
			print(pre,a[i-1]);
		}		
		cout<<endl;
	}
}
