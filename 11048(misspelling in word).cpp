//	here we need to check for misspeling of 3 types - one char is missing , one char is extra , two char are swapped
//	for last condition we'll chk all swapped position in given dictionary ( O( len*log n ))
//	for first one we erase one by one and search it in dictionary O( len*log n )
//	for second we'll give 'a' to 'z' as new char at all position and then search O( 26*len*log n ) 

#include<bits/stdc++.h>
using namespace std;
bool comp(string str1 , string str2)
{
   if(str1 == str2)
   	   return 0;
   int i = 0;
   int l = str1.length();
   int m = str2.length();
   while ((str1[i] == str2[i] || ( str1[i]=='.' || str2[i]=='.'))  && i<l && i<m )
      i++;
   if(i!=l && i!=m)
   	  return (str1[i] - str2[i])<0 ;
   if(i==l)
   	  return 1;
   return 0;
}
int main()
{
	string str,keep;
	vector<string> v;	char c;
	int n,q;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		v.push_back(str);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	cin>>q;
	while(q--)
	{
		cin>>str;
		keep = str;
		int l = str.length();
		for(int i=0;i<l-1;i++)
		{
			swap(str[i],str[i+1]);
			cout<<str<<endl;
			if(binary_search(v.begin(),v.end(),str,comp))
			{
				cout<<keep<<" is a misspelling of "<<v[lower_bound(v.begin(),v.end(),str,comp) - v.begin()]<<endl;
				goto exit;
			}
			swap(str[i],str[i+1]);
		}
		for(int i=0;i<l;i++)
		{
			c = str[i];
			str[i] = '.';
			cout<<str<<endl;
			if(binary_search(v.begin(),v.end(),str,comp))
			{
				cout<<keep<<" is a misspelling of "<<v[lower_bound(v.begin(),v.end(),str,comp) - v.begin()]<<endl;
				goto exit;
			}
			str[i] = c;
		}
		for(int i=0;i<l+1;i++)
		{
			str.insert(i,1,'.');
			cout<<str<<endl;
			if(binary_search(v.begin(),v.end(),str,comp))
			{
				cout<<keep<<" is a misspelling of "<<v[lower_bound(v.begin(),v.end(),str,comp) - v.begin()]<<endl;
				goto exit;
			}
			str.erase(str.begin()+i);
		}
		for(int i=0;i<l;i++)
		{
			c = str[i];
			str.erase(str.begin()+i);
			cout<<str<<endl;
			if(binary_search(v.begin(),v.end(),str,comp))
			{
				cout<<keep<<" is a misspelling of "<<v[lower_bound(v.begin(),v.end(),str,comp) - v.begin()]<<endl;
				goto exit;
			}
			str.insert(i,1,c);
		}
		cout<<keep<<" is unknown\n";
		continue;
		exit:
		;
	}
}
