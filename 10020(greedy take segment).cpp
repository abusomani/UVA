//		Greedily just take the segments

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int m;
bool overlap(ii p)
{
	if(p.second <= 0)
		return 0;
	if(p.first >=m)
		return 0;
	return 1;
}
int main()
{
	int t,i,x,y,maxi,keep;
	ii p,last ;
	cin>>t;
	vector<ii> ans,v;
	while(t--)
	{
		cin>>m;
		while(1)
		{
			cin>>x>>y;
			if(x==0 && y==0)	break;
			p = ii(x,y);
			if(overlap(p) == 1)
			{
				v.push_back(p);	
			}
		}
		sort(v.begin(),v.end());
		v.push_back(ii(m,m+1));
		maxi = 0;
		for(i=0;i<v.size();i++)
		{
			if(v[i].second > maxi && v[i].first <=0 )
			{	last = v[i];	ans.push_back(last);	break;	}
		}
	
		for(;i<v.size();i++)
		{
			if(v[i].second > last.second)
			{
				//cout<<"OO"<<i<<endl;
				if(v[i].first > last.second)
				{
					//cout<<"I"<<i<<endl;
					if(keep == -1)		break;
					last = v[keep];
					ans.push_back(last);
					maxi = 0;	keep = -1;
					continue;
				}
				if(v[i].second >= maxi)
				{
					maxi = v[i].second;
					keep = i;
				}
			}
		}
		//if()
		//cout<<"A"<<ans.size()<<endl;
		if(i!=v.size() || last.second<m)
			cout<<"0\n";
		else
		{ 
			cout<<ans.size()<<endl;
			for(i=0;i<ans.size();i++)
				cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
		if(t)
			cout<<endl;
		v.clear();
		ans.clear();
	}
}
