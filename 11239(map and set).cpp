#include<bits/stdc++.h>
using namespace std;
typedef pair<int, string> ii;
typedef pair<string, set<string> > ii2;
int main()
{
	set<string> st,final,keep;
	set<string>:: iterator p;
	vector<ii> v;
	vector<ii2> ans;
	string str,user,pro;
	int ct;
	while(1)
	{
		st.clear();
		final.clear();
		keep.clear();
		v.clear();
		ans.clear();
		cin>>str;
		if(str=="0")	break;
		pro = str;
		while(1)
		{
			cin>>str;
			if(user=="1")	break;
			if(isupper(user[0]))
			{
				set<string> tp = st;
				ans.push_back(ii2(pro,tp));
				pro = user;
				st.clear();
			}
			else
			{
				st.insert(user);
			}
		}
	
		for(int i=0;i<ans.size();i++)
		{
			st = ans[i].second;
			p = st.begin();
			cout<<st.size()<<endl;
			while(p!=st.end())
			{
				cout<<*p<<endl;
				if(final.find(*p) == final.end())
					keep.insert(*p);
				else
					final.insert(*p);
				p++;
			}
		}
		for(int i=0;i<ans.size();i++)
		{
			st = ans[i].second;
			p = st.begin();
			ct = 0;
			while(p!=st.end())
			{
				if(keep.find(*p) == keep.end())
					ct++;
				p++;
			}
			v.push_back(ii(ct,ans[i].first));
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i].second<<" "<<v[i].first<<endl;
		}
	}
}
