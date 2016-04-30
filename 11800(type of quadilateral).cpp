//	geoetric problem based on distance and slope and then getting the quadilateral shape

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
void convert(ii *s)
{
	int g;
	for(int i=0;i<6;i++)
	{
		if(s[i].first<0 && s[i].second<0)
		{
			s[i].first = -s[i].first;
			s[i].second = -s[i].second;
		}
		else if(s[i].second<0)
		{
			s[i].first = -s[i].first;	
			s[i].second = -s[i].second;
		}

		g = gcd(abs(s[i].first),abs(s[i].second));
		s[i].first /= g;
		s[i].second /= g;
	}
}
int cal_dis(ii& a,ii &b)
{
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second) ;
}
bool ck_for_rhombus(int *dis)
{
	int k,flag;
	for(int i=0;i<6;i++)
	{
		k = dis[i];
		flag = 0;
		for(int j=0;j<6;j++)
		{
			if(k==dis[j])
				flag++;
		}
		if(flag==4)
			return 1;
	}
	return 0;
}
int main()
{
	int t,x,y;
	ii a[4];
	ii slope[6];
	set<ii> st;
	set<int> distance;
	int dis[6];
	int temp[3];
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		for(int i=0;i<4;i++)
		{
			cin>>x>>y;
			a[i] = ii(x,y);
		}
		slope[0] = ii(a[1].second-a[0].second,a[1].first-a[0].first);
		slope[1] = ii(a[2].second-a[0].second,a[2].first-a[0].first);
		slope[2] = ii(a[3].second-a[0].second,a[3].first-a[0].first);
		slope[3] = ii(a[2].second-a[1].second,a[2].first-a[1].first);
		slope[4] = ii(a[3].second-a[1].second,a[3].first-a[1].first);
		slope[5] = ii(a[3].second-a[2].second,a[3].first-a[2].first);
		convert(slope);
		for(int i=0;i<6;i++)
			st.insert(slope[i]);
			//cout<<slope[i].first<<"  "<<slope[i].second<<endl;
		if(st.size()==6)
			cout<<"Case "<<j<<": Ordinary Quadrilateral"<<endl;
		else if(st.size()==5)
			cout<<"Case "<<j<<": Trapezium"<<endl;
		else
		{
			dis[0] = cal_dis(a[0],a[1]);
			dis[1] = cal_dis(a[0],a[2]);
			dis[2] = cal_dis(a[0],a[3]);
			dis[3] = cal_dis(a[1],a[2]);
			dis[4] = cal_dis(a[1],a[3]);
			dis[5] = cal_dis(a[2],a[3]);
			for(int i=0;i<6;i++)
				distance.insert(dis[i]);
			if(distance.size()==2)
				cout<<"Case "<<j<<": Square"<<endl;
			else if(distance.size()==3)
			{
				set<int> ::iterator p = distance.begin();
				int i=0;
				while(p!=distance.end())
				{
					temp[i++] = *p;	p++;
				}
				sort(temp,temp+3);
				if(temp[2]==temp[0]+temp[1])
					cout<<"Case "<<j<<": Rectangle"<<endl;
				else
				{
					if(ck_for_rhombus(dis))
						cout<<"Case "<<j<<": Rhombus"<<endl;
					else
						cout<<"Case "<<j<<": Parallelogram"<<endl;
				}
			}
			else
				cout<<"Case "<<j<<": Parallelogram"<<endl;
		}
		st.clear();
		distance.clear();
	}
}
