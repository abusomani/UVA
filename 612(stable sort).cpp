#include<bits/stdc++.h>
using namespace std;
int inv(string &str)
{
	int ct = 0;
	int l = str.length();
	for(int i=0;i<l;i++)
	{
		for(int j=i;j<l;j++)
		{
			if(str[i]>str[j])
				ct++;
		}
	}
	return ct;
}
struct type
{
	int inv;
	int idx;
};
bool cmp(type a, type b)
{
	if(a.inv != b.inv)
		return a.inv < b.inv;
	return a.idx < b.idx;
}
int main()
{
	int t,l,n;
	string str[102];
	type k[102];
	cin>>t;
	for(int j=0;j<t;j++)
	{
		cin>>l>>n;
		for(int i=0;i<n;i++)
			cin>>str[i];
		for(int i=0;i<n;i++)
		{
			k[i].inv = inv(str[i]);
			k[i].idx = i;
		}
		sort(k,k+n,cmp);
	/*	for(int i=0;i<n;i++)
			cout<<k[i].inv<<"  "<<k[i].idx<<endl;	*/
			
		for(int i=0;i<n;i++)
		{
			cout<<str[k[i].idx]<<endl;
		}
		 if (j!=t-1) {
      			cout << endl;
    	}
	}
}
