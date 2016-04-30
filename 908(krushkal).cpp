#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
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
int main()
{
	int n,a,b,wt,k,sum1,sum2;
	vector<edge> e;
	bool flag = 0;
	while (scanf("%d",&n)==1)
    {
        if (cin.eof()) break;
        if(flag)
        	printf("\n");
        flag = 1;
		sum1 = 0;	
		disjs ds(n);
		for(int i=0;i<n-1;i++)
			scanf("%d %d %d",&a,&b,&wt),
			sum1 += wt;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d %d %d",&a,&b,&wt);
			e.push_back(edge(a,b,wt));
		}
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d %d %d",&a,&b,&wt);
			e.push_back(edge(a,b,wt));
		}
		sort(e.begin(),e.end(),cmp);
		sum2 = k = 0;
		for(int i=0;i<e.size();i++)
		{
			a = e[i].a;	  b = e[i].b;	 wt = e[i].wt;
			if(k==n)		break;
			if(ds.find(a)!=ds.find(b))
			{
				sum2 += wt;
				ds.dounion(a,b);
			}
			k++;
		//	cout<<"s";
		}
		printf("%d\n%d\n",sum1,sum2);
		e.clear();
	}
}
