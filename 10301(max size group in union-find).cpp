//		two circle intersect if the distance between their centers is in between r1+r2  and  r1-r2

#include<bits/stdc++.h>
#define M 110
#define sqr(x) ((x)*(x))
using namespace std;
int s[M];
int find(int x)					// 	non-recursive
{								
	if(s[x]<0)					// 	for recursive in else - return s[x] = find(s[x])
		return x;
	int y = x;
	for( ; s[y]>0 ; y = s[y]);
	int z = y;
	for( ; x!=z ; x = s[x])
	{
		y = s[x];
		s[x] = z;
	}
	return z;	
}
void dounion(int x,int y)
{
	x = find(x);
	y = find(y);
	if(s[x]>=s[y])
	{
		s[y] += s[x];
		s[x] = y;
	}
	else
	{
		s[x] += s[y];
		s[y] = x;
	}	
}
void show()
{
	///int num=s.size();
	for(int i=0;i<5;i++)
    cout<<i<<"-> "<<s[i]<<endl;
}
struct ring
{
	double a,b,r;
	ring(double aa,double bb,double rr):a(aa),b(bb),r(rr)
	{}
};
vector<ring> v;
double dis(int i,int j)
{
	return sqr(v[i].a - v[j].a) + sqr(v[i].b - v[j].b) ;
}
int main()
{
	int n,minv;
	double a,b,r;
	
	while(1)
	{
		cin>>n;		if(n==-1)		break;
		memset(&s,-1,sizeof(s));
		for(int i=0;i<n;i++)
		{
			cin>>a>>b>>r;
			v.push_back(ring(a,b,r));
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(dis(i,j) <= sqr(v[i].r + v[j].r) && dis(i,j) >= sqr(v[i].r - v[j].r))
				{
					//cout<<i<<j<<"   "<<dis(i,j)<<endl;
					if(find(i) != find(j))
						dounion(i,j);
				}
			}
		}
		//show();
		minv = 2147483647;
		for(int i=0;i<M;i++)
		{
			minv = min(minv,s[i]);
		}
		if(minv != -1)		cout<<"The largest component contains "<<-minv<<" rings.\n";
		else				cout<<"The largest component contains "<<-minv<<" ring.\n";
		v.clear();
	}
}
