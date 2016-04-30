#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;		int i;
	set<string> st;
	string tmp;
	while(getline(cin,str))
	{
		tmp = "";
		int  l = str.length();
		for(i=0;i<l;i++)
		{
			str[i] = tolower(str[i]);
		}
		for(i=0;i<l;i++)
		{
			if(islower(str[i]))
			{
				tmp += str[i];
			}
			else
			{
				if(tmp.length()>0)
					st.insert(tmp);
	//			cout<<tmp<<endl;
				tmp = "";
			}
		}
		if(tmp.length()>0)
			st.insert(tmp);
	//	cout<<tmp<<endl;
	//			tmp = "";
	}
	set<string> :: iterator p = st.begin();
	while(p!=st.end())
	{
		cout<<*p<<endl;
		p++;
	}
	
}
