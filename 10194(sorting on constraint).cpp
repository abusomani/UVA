//    sorting based on varoius constraints

#include<bits/stdc++.h>
using namespace std;
struct team
{
	string name;
	int rank;
	int pt;
	int tg;
	int w,l,t;
	int gs,ga;
	team()
	{
		tg = 0;
		pt = 0 ;
		w=l=t= 0;
		gs = ga = 0;
	}
};
bool cmp(team a,team b)
{
	if(a.pt==b.pt)
	{
		if(a.w==b.w)
		{
			if(a.gs-a.ga == b.gs-b.ga)
			{
				if(a.gs==b.gs)
				{
					if(a.tg==b.tg)
					{
						return a.name < b.name;
					}
					return (a.tg > b.tg);
				}
				return (a.gs < b.gs);
			}
			return (a.gs-a.ga < b.gs-b.ga);
		}
		return (a.w)<(b.w);
	}
	return (a.pt)<(b.pt);
}
int main()
{
	int t,teams,played,g1,g2;
	cin>>t;
	map<string,team> mp;
	vector<team> v;
	string tourna,temp;
	char input[100];
	while(t--)
	{
		getchar();
		getline(cin,tourna);
		
		cin>>teams;
		for(int i=0;i<teams;i++)
		{
			cin>>temp;
			team a ;  a.name = temp;
			mp[temp] = a;
		}
		cin>>played;
		while(played--)
		{
			gets(input);
            char buff;
            stringstream s(input);
        	
        	string temp1;		string temp2;
            getline(s,temp1,'#');
            s >> g1 >> buff >> g2 >> buff;
            getline(s,temp2);
            
            cout<<temp1<<"  "<<g1<<"  "<<g2<<"  "<<temp2<<endl;
            
			team& a = mp[temp1];
			team& b = mp[temp2];
			cout<<a.name<<"   "<<b.name<<endl;
			
			a.tg++;		b.tg++;
			if(g1>g2)		 {	a.w++;	b.l++;	}
			else if(g1<g2)	 {	a.l++;	b.w++;	}
			else			 {	a.t++;	b.t++;	}
			a.gs += g1;		a.ga += g2;
			b.gs += g2;		b.ga += g1;
		}
		
		map<string,team> :: iterator p = mp.begin();
		while(p!=mp.end())
		{
			
			(p->second).pt = 3*(p->second).w + (p->second).t;
			v.push_back(p->second);
			p++;
		}
	
		sort(v.begin(),v.end(),cmp);
		cout<<tourna<<endl;
		for(int i=0;i<v.size();i++)
		{
			cout<<i+1<<") "<<v[i].name<<" ";
			cout<<v[i].pt<<"p, "<<v[i].tg<<"g "<<"("<<v[i].w<<"-"<<v[i].t<<"-"<<v[i].l<<"), ";
			cout<<v[i].gs-v[i].ga<<"gd ("<<v[i].gs<<"-"<<v[i].ga<<")\n";
		}
		v.clear();
	}
}
