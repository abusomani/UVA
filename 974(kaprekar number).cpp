#include<bits/stdc++.h>
#define M 40000
using namespace std;
int tpow[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int chk(int n1)
{
	int keep = n1;
	n1 = n1*n1;
	int n2=0;
	int i = 0;
	while(n1>0)
	{
		n2 = (n1%10) * tpow[i] + n2;
		n1/=10;
	//	cout<<n1<<"  "<<n2<<endl;
		if(n2 != 0 && n1+n2 == keep)
			return 1;
		i++;
	}
	return 0;
}
bool visit[M+100];
int main()
{
	vector<int> v;
	memset(&visit,0,sizeof(visit));
	for(int i=1;i<=M;i++)
	{
		if(chk(i) == 1)
		{
			visit[i] = 1,
			v.push_back(i);
			
			cout<<i<<endl;
		}
	}
	int t,a,b,cnt;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>a>>b;
		cnt = 0;
		printf("case #%d\n",j);
		for(int i=0;i<v.size();i++)
		{
			if(v[i]>=a && v[i]<=b)
			{
				cout<<v[i]<<endl;
				cnt++;
			}	
		}
		if(cnt == 0)		
			printf("no kaprekar numbers\n");
				
		if(j != t)	cout<<endl;
	}
}
