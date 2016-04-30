#include<bits/stdc++.h>
using namespace std;
typedef pair<int,string> ii;
int main()
{
	int t,sum,n,m,b,items,p;
	map<string,int> price;
	string name,dish,str;
	vector<ii> v;
	cin>>t;
	while(t--)
	{
		//cin>>name;
		cin.ignore(100,'\n');
		getline(cin,name);
		for(int i=0;i<name.length();i++)
			if(name[i]!=' ')	name[i] = toupper(name[i]);
		
		cin>>n>>m>>b;
		for(int i=0;i<n;i++)
		{
			cin>>str>>p;
			price[str] = p;
		}
		for(int i=0;i<m;i++)
		{
			//cin>>dish;
			cin.ignore(100,'\n');
			getline(cin,dish);
			cin>>items;
			sum = 0;
			for(int i=0;i<items;i++)
			{
				cin>>str>>p;
				sum += p*price[str];
			}
			if(sum<=b)
				v.push_back(ii(sum,dish));
		}
		sort(v.begin(),v.end());
		cout<<name<<endl;
		if(!v.size())
			cout<<"Too expensive!\n";
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i].second<<endl;
		}
		cout<<endl;
		price.clear();
		v.clear();
	}
}
