#include <bits/stdc++.h>
#define M 120005
using namespace std;
int main()
{
	int n = 0;
	string str[M];	
	string tmp1,tmp2;
	while(cin>>str[n++]);
	
	sort(str,str+n);
	for (int i = 0; i < n; i++)
	{
		for(int j = 1; j<str[i].length() ; j++)
		{
			tmp1 = str[i].substr(0,j);
			tmp2 = str[i].substr(j,str[i].size()-1);
			//cout<<tmp1<<"  "<<tmp2<<endl;
			if(binary_search(str,str+n,tmp1)  &&  binary_search(str,str+n,tmp2))
			{
				cout<<str[i]<<endl;
				break;
			}
		}
	}
}
