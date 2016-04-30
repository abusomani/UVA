//	question based on sorting of x co-ordinates and one bool variable for knowing line starts or ends

#include<bits/stdc++.h>
using namespace std;
struct xval
{
	double x;
	bool start;
	double val;
	xval(double x,bool start,double val)
	{
		this->x = x;	this->start = start;	this->val = val;
	}
};
struct ans
{
	double start;
	double end;
	double val;
	ans(double start,double end,double val)
	{
		this->start = start;	this->end = end;	this->val = val;
	}
};
bool cmp(xval a, xval b)
{
	return (a.x<b.x);
}

int main()
{
	int t,lines;
	double x1,y1,x2,y2,val,e;
	vector<xval> pt;
	vector<ans> a;
	vector<double> on;
	cin>>t;
	while(t--)
	{
		cin>>lines;
		for(int i=0;i<lines;i++)
		{
			cin>>x1>>y1>>x2>>y2>>val;
			if(x1>x2)	swap(x1,x2);
			pt.push_back(xval(x1,1,val));
			pt.push_back(xval(x2,0,val));
		}
		sort(pt.begin(),pt.end(),cmp);
		
		on.push_back(pt[0].val);
		e = pt[0].val;
		cout<<2*lines+1<<endl;
		
		printf("-inf %.3f 1.000\n",pt[0].x);
		for(int i=1;i<pt.size();i++)
		{
			if(pt[i-1].x != pt[i].x)
				printf("%.3f %.3f %.3f\n",pt[i-1].x,pt[i].x,e);
				
			if(pt[i].start)
				e *= pt[i].val;
			else
				e /= pt[i].val;
		}
		printf("%.3f +inf 1.000\n",pt[pt.size()-1].x);
		if ( t )	
			puts( "" );
	}	
}
