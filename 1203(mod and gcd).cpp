#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int gcd(int m, int n)     	
{
   int  r;                
   while (n != 0) 
   {      
      r = m % n;          
      m = n;            
      n = r;
   }                      
   return m;              
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int i = 0,n,num,t,k,g,mint;
	bool exit;
	string str;
	vector<ii> v;
	mint = 2147483647;
	while(1)
	{
		cin>>str;
		if(str=="#")	break;
		cin>>num>>t;
		mint = min(t,mint);
		v.push_back(ii(num,t));
		i++;
	}
	cin>>k;
	exit = 0;
	n = i;	g = 0;
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		g = gcd(g,v[i].second);
	}
	n = mint;		t = 0;
	while(1)
	{
		
		for(int i=0;i<v.size();i++)
		{
			if(n % v[i].second ==0)
			{
				t++;
				cout<<v[i].first<<endl;
				if(t==k)
				{
					exit = 1;
					break;
				}
			}
		}
		n += g;
		if(exit)	break;
	}
}
