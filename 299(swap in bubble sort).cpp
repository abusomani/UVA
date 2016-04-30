#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,ct;
	int a[100];
	cin>>t;
	while(t--)
	{
		cin>>n;
		ct = 0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(a[i]>a[j])
					swap(a[i],a[j]),
					ct++;
			}
		}
		cout<<"Optimal train swapping takes "<<ct<<" swaps."<<endl;
	}	
}
