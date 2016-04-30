#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,traverse,cases,proc;
	queue<int> left,right;
	bool pos = 0;
	string dir;
	cin>>cases;
	while(cases)
	{
		cin>>n>>m>>traverse;
		proc = 0;
		for(int i=0;i<m;i++)
		{
			cin>>t>>dir;
			if(dir=="left")		left.push(t);
			if(dir=="right")	right.push(t);
		}
		t = 0;
		while(proc != m)
		{
			
			t += traverse;
		}
	}
}
