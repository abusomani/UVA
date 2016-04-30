/*
	In this question we need to get cycle length in sequence based on function given in postfix notation
*/
#include<bits/stdc++.h>
using namespace std;
vector<string> func;				//	it stores function
typedef long long ll;

ll n;
bool isoprt(char x)
{
	if(x=='+' || x=='*' || x=='%')
		return 1;
	return 0;
}
ll atoi(string s)
{
	ll num = 0;
	for(int i=0;i<s.size();i++)
		num = num*10 + s[i]-'0';
	return num;
}
ll calc(ll a,ll b,char c)
{
	if(c=='+')		return a+b;
	if(c=='*')		return a*b;
	if(c=='%')		return b%a;
}
ll f(ll x)
{
	ll a,b;
	stack<ll> st;
	for(int i=0;i<func.size();i++)
	{
		if(func[i] == "x")
		{
			st.push(x);
		}
		else if(isoprt(func[i][0]))
		{
			a = st.top();		st.pop();
			b = st.top();		st.pop();
			st.push(calc(a,b,func[i][0]));
		}
		else
			st.push(atoi(func[i]));
	}
	return st.top();
}

ll floyd()
{
	ll slow,fast;
	slow = f(n);	fast = f(f(n));
	while(slow != fast)
	{
	//	cout<<slow<<"  "<<fast<<endl;
		slow = f(slow);
		fast = f(f(fast));		
	}
//	cout<<slow<<"  "<<fast<<endl;
	slow = n;					//	reset pointer to start
	while(slow != fast)
	{
		slow = f(slow);
		fast = f(fast);
	}
	fast = f(fast);
	ll lambda = 1;
	while(slow != fast)
	{
		fast = f(fast);
		lambda++;
	}
	return lambda;
}
int main()
{
	string str,tmp,N;
	while(1)
	{
		getline(cin,str);
		istringstream iss(str);
		iss>>N>>n;
		if(N=="0")		break;
		while(iss >> tmp)
		{
			if(tmp == "N")
				func.push_back(N);
			else
				func.push_back(tmp);
		}
		cout<<floyd()<<endl;
		func.clear();
	}
}
