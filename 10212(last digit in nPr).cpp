/*	last digit in nPr	we will loop from n to n-r+1 and for each number remove power of 2 and 5
 		( and store extra power of two  after removing pairs of 2 and 5 )		
 then multiply with extra power if pow(5) > pow(2)  then ans will be 5 because any odd * 5 's last digit is 5 */ 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n , m;
	long long ans,temp;
	int two;
	while(cin>>n>>m)
	{
		ans = 1;	two = 0;
		if(m == 0)		ans = 1;
		else
		for(int i=0 ; i<m ; i++)
		{
			temp = n-i;
			while(temp%2 == 0)
			{
				temp /= 2;
				two++;
			}
			while(temp%5 == 0)
			{
				temp /= 5;
				two--;
			}
			ans = (ans * temp) % 10;
		}		
		for(int i=0;i<two;i++)
			ans = (ans * 2) % 10;
		if(two<0)
			ans = 5;
		cout<<ans<<endl;
	}	
}
