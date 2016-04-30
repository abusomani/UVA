#include<bits/stdc++.h>
#define M 20004
using namespace std;
typedef long long ll;
bool visit[M];
int main()
{
	int n,a;
	vector<int> v;
	int m = 0;
	while(cin>>n)
	{
		m++;
		memset(&visit,0,sizeof(visit));
		for(int i=0;i<n;i++)
		{
			cin>>a;
			v.push_back(a);		
		}	
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if((i!=j && v[i]>=v[j])  || v[i]<1 || visit[v[i] + v[j]])
				{	printf("Case #%d: It is not a B2-Sequence.",m);		goto end;	}
				visit[v[i] + v[j]] = 1;
				//cout<<v[i]+v[j]<<endl;
			}
		}
		printf("Case #%d: It is a B2-Sequence.",m);
		end:
			cout<<endl<<endl;
		v.clear();
	}
}
