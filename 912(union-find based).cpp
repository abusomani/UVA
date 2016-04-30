//	Good question on union find dataset

#include<bits/stdc++.h>
using namespace std;
struct tp
{
	char a,n;
	bool tock;
	tp(char aa,char nn, bool t)	: a(aa),n(nn),tock(t)
	{
	}
};
class Disjset
{
	private:
		vector<int> s;
	public:
	Disjset(int num)
	{
		for(int i=0;i<num;i++)
	    s.push_back(-1);
	}
	int find(int x)
	{
		if(s[x]<0)
			return x;
		else
			return s[x]=find (s[x]);
	}
	void dounion(int root1,int root2)
	{
		if(s[root1]>=s[root2])
		{
			s[root2]+=s[root1];
			s[root1]=root2;
		}
		else
		{
			s[root1]+=s[root2];
			s[root2]=root1;
		}
	}
	void show()
	{
		int num=s.size();
		for(int i=0;i<num;i++)
	    cout<<i<<"-> "<<s[i]<<endl;
	}
};
int main()
{
	int n;
	vector<tp> v;
	int ch[10];		char s[10];
	while (true)
    {
        cin >> n;
        Disjset ds(50);
        string dummy;
        getline(cin, dummy);
        if (cin.eof())
        {
            break;
        }
		v.clear();
		bool exit = 0;
		memset(&ch,0,sizeof(ch));
		sscanf(s, "%d", &n);
		char str1[n],str2[n];
		for(int i=0;i<n;i++)
		{
			cin>>str1[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>str2[i];
		}
		for(int i=0;i<n;i++)
		{
			if(str1[i] != str2[i])
			{
				if(isalpha(str1[i])  &&  isalpha(str2[i]))
				{	cout<<"NO\n\n";	exit = 1;	break;	}
				
				if(isalpha(str1[i])  &&  isdigit(str2[i]))
				{	v.push_back(tp(str1[i],str2[i],1));		}
				
				if(isalpha(str2[i])  &&  isdigit(str1[i]))
				{	v.push_back(tp(str2[i],str1[i],1));		}
				
				if(isdigit(str1[i])  &&  isdigit(str2[i]))
				{	v.push_back(tp(str1[i],str2[i],0));		}
			}
		}
		
		if(exit)    {   continue;	}
		for(unsigned int i=0;i<v.size();i++)
		{
			if(v[i].tock)
			{
			if(ch[v[i].n-'0'] == 0)
			{
				ch[v[i].n-'0'] = v[i].a;
				ds.dounion(v[i].n-'0',v[i].a-'A'+10);
			//	cout<<"d    "<<v[i].n-'0'<<"  "<<v[i].a-'A'+10<<endl;
			}
			else 
			{
				if(ch[v[i].n-'0'] != v[i].a)
				{	cout<<"NO\n\n";	exit = 1;	break;	}
			}
			}
		}
	//	ds.show();
		if(exit)    {   continue;	}
		for(unsigned int i=0;i<v.size();i++)
		{
			if(!v[i].tock)
			{
				ds.dounion(ds.find(v[i].n-'0'),ds.find(v[i].a-'0'));
			}
		}
		for(unsigned int i=0;i<v.size();i++)
		{
			if(!v[i].tock)
			{
				
				if(ch[v[i].n-'0'] == 0 || ch[v[i].a-'0'] == 0)
				{
					if(ch[v[i].n-'0'] == 0)
						ch[v[i].n-'0'] = ds.find(v[i].n-'0') - 10 +'A';
			
					if(ch[v[i].a-'0'] == 0)
						ch[v[i].a-'0'] = ds.find(v[i].a-'0') - 10 +'A';
				}
				
				if(ds.find(v[i].n-'0') != ds.find(v[i].a-'0'))
					{	cout<<"NO\n\n";		exit = 1;	break;	}
			}
		}
		for(unsigned int i=0;i<v.size();i++)
		{
			if(!v[i].tock)
			{
				if(ch[v[i].n-'0'] != ch[v[i].a-'0'] )
				{
						cout<<"NO\n\n";		exit = 1;	break;
				}
			}	
		}
	//	ds.show();
		for(unsigned int i=0;i<v.size();i++)
		{
			if(!v[i].tock)
			{
				if(ds.find(v[i].n-'0') == v[i].n-'0')
				{	cout<<"NO\n\n";	exit = 1;	break;	}
			}
		}
		if(exit)    {   continue;	}
		cout<<"YES\n";	
		int y = 0;
		for(int i=0;i<10;i++)
		{	if(ch[i]<'A' || ch[i]>'Z')  y++;	}
		//cout<<"dd"<<y<<endl;
		if(y!=10)
		for(int i=0;i<10;i++)
		{
			if(ch[i] != 0)
				cout<<i<<" "<<(char)ch[i]<<endl;
		}
		cout<<endl;
	}
}
