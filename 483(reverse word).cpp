#include<bits/stdc++.h>
using namespace std;
void strev(string &s)
{
	int l = s.length();
	char temp;
	for(int i=0;i<l/2;i++)
	{
		temp = s[i];
		s[i] = s[l-i-1];
		s[l-i-1] = temp;
	}
}
int main()
{
	string str,temp,ans;
	while(getline(cin,str))
	{
		istringstream iss(str);
		ans = "";
		while(iss>>temp)
		{
			strev(temp);	
			ans += temp+" ";
		}
		ans.erase(ans.length()-1);
		cout<<ans<<endl;
	}
}
