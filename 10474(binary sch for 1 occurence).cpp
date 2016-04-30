#include<bits/stdc++.h>
using namespace std;
int sch(vector<int>& v,int item,int low,int high)
{
	int mid = (low+high)/2;
	while(low <= high)
	{
		//cout<<low<<"  "<<high<<endl;
		if((mid>0 && v[mid]==item && v[mid]>v[mid-1])||(mid==0 && v[mid]==item) )
			return mid;
		else if(v[mid]<item)
			low = mid+1;
		else
			high = mid-1;
		mid = (low+high)/2;
	}
	return -1;
}
int main()
{
	int p,n,a,q,k;
	vector<int> v;
	for(int j=1;1;j++)
	{
		cin>>n>>q;
		if(!n && !q)		break;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		cout<<"CASE# "<<j<<":\n";
		while(q--)
		{
			cin>>p;
			k = sch(v,p,0,n-1);
			if(k!=-1)
				cout<<p<<" found at "<<k+1<<endl;
			else
				cout<<p<<" not found\n";
		}
		v.clear();
	}
}
