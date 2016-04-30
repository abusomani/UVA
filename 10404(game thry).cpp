/*	here we can subtract and number from n from a given list so will follow botttom up approach i.e. we will start 
	from 1 if we are at i and if there are no precedor ( n-m[0] or n-m[1] or .. ) at which we can win then this a 
	loosing position otherwise winning.
*/
#include<iostream>
#include<string.h>
#define M 1000005
using namespace std;
int main()
{
	int j,n,m;
	int sub[15];
	bool win[M];
	while(cin>>n)
	{
		memset(&win,0,sizeof(win));
		cin>>m;
		for(int i = 0 ; i<m ; i++)
			cin>>sub[i];
	
		for(int i=0;i<m;i++)				
			win[sub[i]] = 1;					//	these are already winning positions.
			
		for(int i = 2 ; i<=n ; i++)
		{
			if(win[i] == 1)		continue;
			for(j=0 ; j<m ; j++)
			{
				if(i-sub[j]>0 && win[i-sub[j]] == 0)
					break;
			}
			if(j == m)
				win[i] = 0;
			else
				win[i] = 1;
		//	cout<<i<<" : "<<win[i]<<endl;
		}
		if(win[n])
			cout<<"Stan wins";
		else
			cout<<"Ollie wins";
		cout<<endl;
	}
}
