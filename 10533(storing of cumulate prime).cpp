//		here all digit prime (acc to def.)  are stored in array and this pre processed array is used later

#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
#define sfast(x) scanf("%d",&x)
#define M 1000003
using namespace std;
vector<int> prime;
bool mark[M];

void markmultiples(int n,int k)
{
	for(int i=k+k;i<n;i+=k)
		mark[i] = 0;
}
void sieve(int n)
{
	memset(&mark,1,sizeof(mark));
	mark[1] = 0;
	markmultiples(n,2);
	for(int i=3;i<n;i+=2)
	{
		if(mark[i] == 1)
		{
			markmultiples(n,i);
		}
	}
}

int dig(int n)
{
	int sum = 0;
	while(n>0)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}
/*
#define gc getchar_unlocked
void sfast(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
*/
int main()
{
	sieve(M);
	int t,a,b,ct;
	int store[M];
	ct = 0;
	for(int i=1;i<M;i++)
	{
		if(mark[i] && mark[dig(i)])
			ct++;
		store[i] = ct;
	}
	sfast(t);
	while(t--)
	{
		sfast(a);	sfast(b);
		ct = store[b] - store[a-1];
		printf("%d\n",ct);
	}
}
