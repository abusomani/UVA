///   Balancing of two brackets

#include<bits/stdc++.h>
using namespace std;
bool flip(char a,char b)
{
	if(a==']' && b=='[')
		return 1;
	if(a==')' && b=='(')
		return 1;
	return 0;
}
int main()
{
	int t;
	stack<char> st;
	string str;
	char s[130];
	cin>>t;
	gets(s);
	while(t--)
	{
		cin>>str;
		if(str=="")
        {
            cout<<"Yes"<<endl;
            continue;
        }	
		int l = str.length();
		for(int i=0;i<l;i++)
		{
			if(str[i]=='(' || str[i]=='[')
				st.push(str[i]);
			else
			{
				if(st.size()  &&  flip(str[i],st.top()))
					st.pop();
				else
					{	st.push(str[i]);	}
			}
		}
		
		if(st.size()>0)
			cout<<"No\n";
		else
			cout<<"Yes\n";
		while(!st.empty())
			st.pop();
	}
}
