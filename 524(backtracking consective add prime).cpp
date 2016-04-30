//	problem based on backtracking all possible solution where addition of adjacent is prime
#include<bits/stdc++.h>
#define M 20
using namespace std;
int n;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
bool visit[M];

bool isprime(int k)
{
	for(int i=0;i<13;i++)
		if(k == prime[i])
			return 1;
	return 0;
}
void construct_condidate(int a[],int k,int c[],int *ncondidates)
{
	memset(&visit,0,sizeof(visit));
	for(int i=0;i<k;i++)
		visit[a[i]] = 1;
	for(int i=1;i<=n;i++)
	{
		if(!visit[i]  &&  isprime( a[k-1]+i ))
			c[(*ncondidates)++] = i;
	}
}
int sol;
void process(int a[])
{
//	sol++;
	cout<<a[0];
	for(int i=1;i<=n-1;i++)
		cout<<" "<<a[i];
	cout<<endl;
}
bool is_a_solution(int a[],int k)
{
	if(k == n-1)
	{
		if( isprime(a[0]+a[n-1]) )
			return 1;	
	}
	return 0;
}
void backtrack(int a[],int k)
{
	int c[n];
	int ncondidates = 0;
	if(is_a_solution(a,k))
		process(a);
	else
	{
		k++;
		construct_condidate(a,k,c,&ncondidates);
		for(int i=0;i<ncondidates;i++)
		{
			a[k] = c[i];
			backtrack(a,k);
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int j = 1;
	int a[M];
	while(cin>>n)
	{
		printf("Case %d:\n",j++);
		a[0] = 1;
		backtrack(a,0);
		cout<<endl;
	}
}
