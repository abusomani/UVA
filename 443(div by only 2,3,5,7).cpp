#include<bits/stdc++.h>
#define MAX 2147483647
#define M 21
using namespace std;
int getmin(int *a)
{
	int idx = 0;	int minv = MAX;
	for(int i=0;i<4;i++)
	{
		if(minv > a[i])
		{
			minv = a[i];
			idx = i;
		}
	}
	return idx;
}
int main()
{
	int a[4] = {2,3,5,7};
	int v[4] = {2,3,5,7};
	vector<int> humble;
	humble.push_back(1);
	int m,val;
	for(int i=1;i<M;i++)
	{
		m = getmin(a);
		val = a[m];
		//cout<<'#'<<m<<"  "<<a[m]<<"  ";
		humble.push_back(a[m]);
		
		for(int i=0;i<4;i++)
		{
			if(a[i] == val)
				a[i] *= v[i];
		}
		
	
		for(int i=0;i<4;i++)
			cout<<a[i]<<"  ";
		cout<<endl;
	
	}
	for(int i=0;i<humble.size();i++)
	{
		cout<<humble[i]<<endl;
	}
}
