#include<bits/stdc++.h>
#define M 100
using namespace std;
typedef vector<vector<int> > vvi;

int in[M];
vector<string> ans;
vector<int> st;
bool visit[M];
string str[M];

void topo(vector<vector<int> > &g)
{
	bool flag = 0;
	int v;
	for(int i  = 0; i<g.size() ; i++)
	{
		if(in[i]==0 && !visit[i])
		{
			for(int j = 0;j<g[i].size();j++)
			{
				v =  g[i][j];
				in[v]--;
			}
			st.push_back(i);
			visit[i] = 1;
			topo(g);
			visit[i] = 0;
			st.erase(st.end()-1);
			for(int j=0;j<g[i].size();j++)
			{
				v = g[i][j];
				in[v]++;
			}
			flag = 1;
		}
	}
	if(!flag)
	{
		string tmp = "";
		for(int i=0;i<st.size();i++)
		{
		//	cout<<st[i];
			tmp += str[st[i]];
		}
	//	cout<<endl;
		ans.push_back(tmp);
	}
}
int main()
{
	int i;
	string str1,str2,var,cons;
	map<string,int> mp;
	bool blank = false;
	while(getline(cin,var))
	{
		istringstream iss1(var);
		i = 0;
		memset(&in,0,sizeof(in));
		memset(&visit,0,sizeof(visit));
		while(iss1>>str[i])
		{
			mp[str[i]] = i++;
		}
		vvi g(i);
		getline(cin,cons);
		istringstream iss(cons);
		while(iss>>str1>>str2)
		{
			g[mp[str1]].push_back(mp[str2]);
			in[mp[str2]]++;
		}
	//	showgraph(g);
		topo(g);
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<endl;
		}
		if ( blank ) printf ("\n");
        blank = true;

		mp.clear();
		g.clear();
		ans.clear();
		st.clear();
	}
}
