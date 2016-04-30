#include<bits/stdc++.h>
#define M 200005
#define S 100000
using namespace std;
int Count[M];
int start[M];
int v[M];
int st[1000000],freq;

void make_tree(int lo,int hi,int idx)
{
	int mid = (lo+hi)/2;
	if(lo==hi)
		st[idx] = Count[v[lo]];
	else
	{
		make_tree(lo,mid,2*idx);
		make_tree(mid+1,hi,2*idx+1);
		st[idx] = max(st[2*idx] , st[2*idx+1]);
	}
}
int query(int lo,int hi,int i,int j,int idx)
{
	if(i>hi || j<lo)
		return -1;
	if(lo >= i && j >= hi)
		return st[idx];
	int mid = (lo + hi)/2;
	return max(query(lo,mid,i,j,2*idx) , query(mid+1,hi,i,j,2*idx+1)) ;
}
int main()
{
	int i,j,n,k,q;
	int ct1,ct2;
	while(1)
	{
		cin>>n;
		if(n==0)	break;
		cin>>q;
		memset(&Count,0,sizeof(Count));
		for(i=0;i<n;i++)
		{
			cin>>k;
			k += S;
			v[i] = k;
			Count[k]++;
			if(Count[k] == 1)
				start[k] = i;
		}
		make_tree(0,n-1,1);
//		for(i=0;i<23;i++)
//			cout<<st[i]<<"  ";
		while(q--)
		{
			cin>>i>>j;
			i--;	j--;
			if(v[i] == v[j])
			{
				cout<<(j-i+1)<<endl;
				continue;
			}
			else
			{
				ct1 = Count[v[i]] - ( i - start[v[i]] )	;
				ct2 = ( j - start[v[j]] ) + 1; 
				ct1 = max(ct1,ct2);
				i = start[v[i]] + Count[v[i]];
				j = start[v[j]] - 1;
				ct2 = query(0,n-1,i,j,1);
				cout<<max(ct1,ct2)<<endl;
			}
		}
	}	
}
