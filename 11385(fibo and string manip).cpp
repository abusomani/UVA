#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n;
	long long fib[50];
	map<long long,int> mp;
	fib[1] = 1;	fib[2] = 2;
	long long lim = pow(2.0,31) - 1;
	mp[1] = 1;	mp[2] = 2;
	for(int i=3; ; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i] >= lim)	break;
		mp[fib[i]] = i;
	}
	cin>>t;
	int f[50];
	char output[150];
	string str;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>f[i];
		}
		cin.ignore(100,'\n');
		getline(cin,str);
		string tmp = "";
		for(int i=0;i<str.length();i++)
		{	
			if(str[i]>='A' && str[i]<='Z')
			{
				tmp += str[i];
			}
		}
		str = tmp;
		for(int i=0;i<150;i++)
			output[i] = ' ';
		for(int i=0;i<n;i++)
		{
		//	cout<<mp[f[i]]<<"  "<<str[i]<<endl;
			output[mp[f[i]]-1] = str[i];
		}
		int j,k;
		
		for(int i=149;i>=0;i--)
			if(output[i] != ' ')
			{
				k = i;
				break;
			}
		for(j=0;j<=k;j++)
			cout<<output[j];
			
		cout<<endl;
	}
}
