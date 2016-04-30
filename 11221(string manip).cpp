#include<bits/stdc++.h>
#define M 300
using namespace std;
int main()
{
	int t,x,y,i,m;
	cin>>t;
	string str,temp;
	char ch[M][M];
	int dx[] = {1,0,-1,0};
	int dy[] = {0,1,0,-1};
	string h[4];
	double d;
	for(int j=0;j<=t;j++)
	{
		temp = h[0] = h[1] = h[2] = h[3] = "";
		getline(cin,str);
		int l = str.length();
		for(i=0;i<l;i++)
		{
			if(str[i] >='a' && str[i] <= 'z')
				temp += str[i];
		}
		int k = temp.length();		double d = sqrt(k);
		if(ceil(d) != floor(d))
		{		goto exit;		}
		//	checking start
		k = ceil(d);
		m = 0;
		for(i=0;i<k;i++)
		{
			for(int z=0;z<k;z++)
			{
				ch[i][z] = temp[m++];
			}
		}
		for(i=0;i<k;i++)
		{
			for(int z=0;z<k;z++)
			{
				cout<<ch[i][z]<<"  ";
			}
			cout<<endl;
		}
		for(i=0;i<k/2;i++)
		{
			h[0] = h[1] = h[2] = h[3] = "";
			for(int z=0;z<4;z++)
			{
				if(z==0 || z==1)    x = y = i;
				else				x = y = k-i-1;
				int rpt = k-2*i;
				for( ; rpt ; x += dx[z] , y+= dy[z])
				{
					h[z] += ch[x][y];
					rpt--;
				}
				if(z>0 && h[z] != h[z-1])
					goto exit;
			}
			
		}
		if(i == k/2)
			printf("Case #%d:\n%d\n",j,k);
		
		continue;
						
		exit:
			printf("Case #%d:\nNo magic :(\n" , j);
	}
}
