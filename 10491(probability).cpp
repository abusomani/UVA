/*
	if you have t doors in which a has cow b has car and then u choose one of them then c doors are opened containing cows 
	then probability of winning car is vvvvv (given below) 
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	int t;
	while(cin>>a>>b>>c)
	{
		t = a+b;
		printf("%.5f\n", (double) b*(t-1)/(t*(t-c-1))) ;
	}
}
