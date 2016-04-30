//	For second best MST we will remove edges from best MST one by one and then calculate Second mst and we will choose 
//	minimum of them  O( V * krushkal )  = O( V^3 )

#include<bits/stdc++.h>
#include<stdio.h>
#define M 104
using namespace std;
bool visit[M][M];
typedef pair<int,int> ii;
int n;

class disjs
{
	private:
		vector<int> s;
	public:
		disjs(int n)
		{
			for(int i=0;i<n;i++)
				s.push_back(-1);
		}
		void clear()
		{
			for(int i=0;i<s.size();i++)
				s[i] = -1;
		}
		int find(int x)
		{
			if(s[x]<0)
				return x;
			else
				return x = find(s[x]);
		}
		void dounion(int a,int b)
		{
			a = find(a);
			b = find(b);
			if(s[a] > s[b])
			{
				s[b] += s[a];
				s[a] = b;
			}
			else
			{
				s[a] += s[b];
				s[b] = a;
			}
		}
};
struct edge
{
	int a;
	int b;
	int wt;
	edge(int a,int b,int wt)
	{
		this->a = a;	this->b = b;	this->wt = wt;
	}
};
bool cmp(edge a,edge b)
{
	return a.wt < b.wt;
}
int getmst(vector<edge>& e,disjs& ds)
{
	int a,b,wt;
	int sum2 = 0 ;
	int k = 0;
	for(int i=0;i<e.size();i++)
	{
		a = e[i].a;	  b = e[i].b;	 wt = e[i].wt;
		if(!visit[a][b] and ds.find(a)!=ds.find(b))
		{
			sum2 += wt;
			ds.dounion(a,b);
			k++;
		}
	}
	if(k != n-1)
		return INT_MAX;
	return sum2;
}
int main()
{
	int a,b,wt,k,t,sum1,sum2;
	vector<edge> e;
	bool flag = 0;
	scanf("%d",&t);
	while(t--)
    {
    	scanf("%d %d",&n,&k);
		disjs ds(n+2);
		vector<ii> keep;
		for(int i=0;i<k;i++)
		{
			scanf("%d %d %d",&a,&b,&wt);
			e.push_back(edge(a,b,wt));
		}
		sort(e.begin(),e.end(),cmp);
		sum1 = k = 0;
		for(int i=0;i<e.size();i++)
		{
			a = e[i].a;	  b = e[i].b;	 wt = e[i].wt;
			if(ds.find(a)!=ds.find(b))
			{
				sum1 += wt;
				ds.dounion(a,b);
			//	cout<<a<<"  "<<b<<"  "<<wt<<endl;
				keep.push_back(ii(a,b));		
			}
		}
		memset(&visit,0,sizeof(visit));
		sum2 = INT_MAX;
		for(int i=0;i<keep.size();i++)
		{
			a = keep[i].first;		b = keep[i].second;
			visit[a][b] = 1;
			ds.clear();
			sum2 = min(sum2 , getmst(e,ds));
			visit[a][b] = 0;
		}
		printf("%d %d\n",sum1,sum2);
		e.clear();
		ds.clear();
		keep.clear();
	}
}
