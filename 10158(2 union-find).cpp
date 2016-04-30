#include<bits/stdc++.h>
#define M 10000
using namespace std;
int s[20020];							// 	union - find array
int find(int x)							//  recursive find
{
	if(s[x]<0)
		return x;
	else
		return s[x] = find(s[x]);
}
void unionset(int a,int b)
{
	a = find(a);
	b = find(b);
	if(s[a]>s[b])
	{
		s[b] += s[a];
		s[a] = b;
	}
	else
	{
		s[a] += s[b];
		s[b] = a;
	}
}
inline int enemy(int x)
{
	return (x+M);
}
int main()
{
	int n,a,b,c;
	cin>>n;
	memset(&s,-1,sizeof(s));
	while(cin>>c>>a>>b , c|a|b)
	{
		if(c==1)
		{
			if(find(a) == find(enemy(b)))		{	cout<<"-1\n";	continue;	}
			unionset(a,b);
			unionset(enemy(a),enemy(b));
		}
		if(c==2)
		{
			if(find(a) == find(b))		{	cout<<"-1\n";	continue;	}
			unionset(a,enemy(b));
			unionset(enemy(a),b);
		}
		if(c==3)
		{
			if(find(a)==find (b))
				cout<<"1\n";
			else
				cout<<"0\n";
		}
		if(c==4)
		{
			 if(find(a) == find(enemy(b)) || find(enemy(a)) == find(b))
			 	cout<<"1\n";
			else
				cout<<"0\n";
		}
	}
}
