#include<bits/stdc++.h>
using namespace std;
int getv(string& str)
{
//	str = "WORDHSFI";
	int l = str.length();
	int minv = 32000;
	for(int i=1;i<l;i++)
	{
		minv = min(minv,abs(str[i]-str[i-1]));
	}
	return minv;
}
int main()
{
	string str,temp,store;
	int k = 0,maxi;
	while(cin>>str)
	{
		temp = str;	k=0;
		maxi = 0;
		while(prev_permutation(str.begin(),str.end()))
		{
			k++;	if(k==11)	break;
			if(getv(str)>=maxi)
			{
				store = str;
				maxi = getv(str);
			}
		//	cout<<str<<"  "<<getv(str)<<endl;
		}
		str = temp;	k=0;
		do
		{
			k++;	if(k==12)	break;
			if(getv(str)>maxi)
			{
				store = str;
				maxi = getv(str);
			}
		}
		while(next_permutation(str.begin(),str.end()));
		cout<<store<<maxi<<endl;
	}
}
