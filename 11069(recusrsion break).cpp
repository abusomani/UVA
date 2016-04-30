/*
	here we need to get number of binary string where no two 1 are consecutive and in every combination you should be in 
	a position that you can't place one more 1 in binary string that is 10001 not allowed because we can put 1 in middle
	so at each position u can have 01 or 001 or 1   so we counted each type seperately with recurrence relation.
*/
#include<bits/stdc++.h>
#define M 100
using namespace std;
int main()
{
	int n;
	int tz[M],oz[M],one[M];
	while(cin>>n)
	{
		if(n<=5)
		{
			if(n<3)		cout<<n<<endl;
			else 		cout<<n-1<<endl;
		}
		else
		{
			tz[5] = oz[5] = 1;
			one[5] = 2;
			for(int i=6;i<=n;i++)
			{
				tz[i] = oz[i-1];
				oz[i] = one[i-1];
				one[i]= tz[i-1] + oz[i-1];
			}
			cout<<(tz[n]+oz[n]+one[n])<<endl;			//     total strings will be add of all
		}
	}
}
