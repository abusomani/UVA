#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;	
	string str;
	set<int> st;
	while(cin>>n && n)
	{
		printf("Original number was %d\n",n);
		while(1)
		{
			stringstream ss;								//	these 3 steps are there to convert int to string
			ss<<n;
			ss>>str;
			sort(str.begin(),str.end());
			b = atoi(str.c_str());
			reverse(str.begin(),str.end());
			a = atoi(str.c_str());
			printf("%d - %d = %d\n",a,b,a-b);
			if(st.count(a-b) == 1)
			{
				printf("Chain length %d\n\n",st.size()+1);
				break;
			}
			else
				st.insert(a-b);
			n = a-b;
		}
		st.clear();
	}
}
