#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b)		return gcd(b,a%b);
	else		return a;
}
int main()
{
	int n,G,i,j;
	G = 0;
    			
	for(int m=1;1;m++)
	{
		cin>>n;
		if(!n)		break;
		G = 0;
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
	   		{
   			   G += gcd(i,j);	
   			}
   		}
   		cout<<G<<endl;
	}
}
