#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,level,times,pos;
	cin>>t;
	while(t--)
	{
		cin>>level>>times;
		pos = 1;
		for(int i=1 ; i<level ; i++)
		{
			if(times %2 == 1)
				pos = 2*pos ;
			else
				pos = 2*pos + 1;
			//cout<<pos<<endl;
			times = ceil(times/2.0);
		}
		cout<<pos<<endl;
	}
	cin>>t;
}
