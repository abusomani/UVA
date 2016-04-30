//	the key point of problem is we can borrow either 1,2 or 3 bottles not more than that so as n  is very less
//	we can loop for 1,2,3 and get the max answer

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,khali,bhari,maxi,ans;
	while(cin>>n)
	{
		khali = maxi = 0;
		for(int i=0;i<3;i++)
		{
			bhari = n;
			ans = 0;
			khali = i;
			while(1)
			{
				khali += bhari;
				ans += bhari;
				bhari = 0;
				bhari += khali/3;
				khali = khali%3;
				if(bhari==0 && khali<3)
					break;
			//	cout<<bhari<<"  "<<khali<<endl;
			}
			if(khali>=i)
				maxi = max(ans,maxi);
		}
		cout<<maxi<<endl;
	}
}
