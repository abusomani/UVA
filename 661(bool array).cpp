#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,c,maxi,pos,sum;
	for(int j=1;1;j++)
	{
		cin>>n>>m>>c;
		if(!n)	break;
		int a[n];
		bool on[n];
		memset(&on,0,sizeof(on));
		for(int i=0;i<n;i++)
			cin>>a[i];
		maxi = 0;
		while(m--)
		{
			cin>>pos;		pos--;
			on[pos] ^= 1;
			sum = 0;
			//cout<<endl<<" : ";
			for(int i=0;i<n;i++)
			{
			//	if(on[i])		cout<<i+1<<"  ";
				sum += on[i]*a[i];
			}
			maxi = max(sum,maxi);
		}
		
		cout<<"Sequence "<<j<<endl;
		if(maxi>c)
			cout<<"Fuse was blown.\n\n";
		else
			cout<<"Fuse was not blown.\nMaximal power consumption was "<<maxi<<" amperes.\n\n";
	}
}
