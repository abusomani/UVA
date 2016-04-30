#include<bits/stdc++.h>
using namespace std;
int step,mod;
int f(int x)
{
	return (x+step)%mod;
}
int floyd()
{
	int slow,fast;
	slow = f(0);	fast = f(f(0));
	while(slow != fast)				//	to get concurrent point
	{
		slow = f(slow);
		fast = f(f(fast));
	}
	slow = 0;
	while(slow != fast)				// to get starting position
	{
//		cout<<slow<<"  "<<fast<<endl;
		slow = f(slow);
		fast = f(fast);
	}
	int lambda = 0;
	fast = f(fast);
	while(slow != fast)
	{
		fast = f(fast);
		lambda++;
	}
	return lambda+1;
}
int main()
{
	int lambda ;
	while(cin>>step>>mod)
	{
		lambda = floyd();
	//	cout<<lambda<<endl;
		printf("%10d%10d",step,mod);
		if(lambda == mod)
			printf("    Good Choice\n");
		else
			printf("    Bad Choice\n");
	}
}
