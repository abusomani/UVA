#include<bits/stdc++.h>
#define M 1000						// one more 0
using namespace std;
typedef pair<int,int> ii;
ii mul[M];
int k = 0;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317};
int bsch(int m,int a,int b)
{
	int p,q,low,high,mid;
	while(low<high)
	{
		mid = (low+high)/2;
		p = mul[mid].first;			q = mul[mid].second;
	//	if(a*q <= b*p  &&  p*q <= m)
		
	}
}
int bschpos(int a,int b)
{
	int low = 0,high = k,mid;
	while(low<high)
	{
	//	mid = (low+high)/2;
		
	}
}
bool cmp(ii a,ii b)
{
	return (a.first * b.second) < (a.second*b.first);
}
int main()
{
	int n,a,b,m;
	int sz = sizeof(prime)/sizeof(int);
	sz = 5;
	for(int i=0;i<sz;i++)
	{
		for(int j=i;j<sz;j++)
		{
			mul[k++] = ii(prime[i] , prime[j]);
		}
	}
	sort(mul,mul+k,cmp);
	for(int i=0;i<k;i++)
		cout<<mul[i].first<<"  "<<mul[i].second<<"   "<<mul[i].first*mul[i].second<<endl;
		
	while(1)
	{
		cin>>m>>a>>b;
		if(m==0 && a==0 && b==0)	break;
		bschpos(a,b);
	}
}
