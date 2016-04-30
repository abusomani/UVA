#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main()
{
	int t,n,d,v;
	string str;
	vector<ii> p;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			getline(cin, str);
			stringstream ss;
			ss << str;
			v = 0;
			while (ss >> d)
				v++;
			p.push_back(ii(v,i+1));
		}
		sort(p.begin(),p.end());
		cout<<p[0].second;
		v = p[0].first;
		for(int i=1;i<p.size();i++)
		{
			if(p[i].first == v)
				cout<<" "<<p[i].second;
			else
				break;
		}
	}
}
