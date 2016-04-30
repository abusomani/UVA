#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll p = 1;
	ll M = 4294967295;
	vector<ll> v;
	bool flag = 0;
	while(1)
	{
	//	cout<<p<<endl;
		v.push_back(p);
		if(flag)	p = p*2;
		else 		p = p*9;
		flag ^= 1;
		if(p>M)		break;
	}
	v.push_back(M);
		
	ll n;	
	int i;
	while(cin>>n)
	{
		flag = 1;
	//	if(n>=2 && n<=9)	{	cout<<"Stan wins.\n";		continue;	}
		for(i=1;i<v.size();i++)
		{
		//	cout<<v[i]<<endl;
			flag ^= 1;
			if(n > v[i-1] && n <= v[i])
			{
				if(!flag)
					cout<<"Stan wins.";
				else
					cout<<"Ollie wins.";
				cout<<endl;
				break;
			}
		}
	}
}
