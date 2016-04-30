//	floyd's cycle finding algorithm	      lambda = length of cycle       mu = starting of cycle 

#include<bits/stdc++.h>
using namespace std;
int z,i,m,l;
int f(int x)
{
	return (z*x + i)%m;
}
int floyd()
{
	int slow,fast;
	slow = f(l);	fast = f(f(l));
	while(slow != fast)
	{
	//	cout<<slow<<"  "<<fast<<endl;
		slow = f(slow);
		fast = f(f(fast));		
	}
//	cout<<slow<<"  "<<fast<<endl;
	slow = l;					//	reset pointer to start
	int mu = 0;					//	starting of cycle
	while(slow != fast)
	{
		slow = f(slow);
		fast = f(fast);
	//	cout<<slow<<"  "<<fast<<endl;
		mu++;
	}
	fast = f(fast);
	int lambda = 0;
	while(slow != fast)
	{
		fast = f(fast);
		lambda++;
	}
	return lambda+1;
}
int main()
{
	int lambda;
	for(int j=1;1;j++)
	{
		cin>>z>>i>>m>>l;
		if(z==0)	break;
		lambda = floyd();
		printf("Case %d: %d\n",j,lambda);
	}
}
