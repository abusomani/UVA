/*	this is called a nim game , here player one wins if nim sum of all piles is NON_ZERO and and player 2 if Nim sum
	is zero  nim sum of A,B,C,D .. = A xor B xor C xor D ..
			http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=algorithmGames
			
	explanation -  From the losing positions we can move only to the winning ones:
				- if xor of the sizes of the piles is 0 then it will be changed after our move 
   	(at least one 1 will be changed to 0, so in that column will be odd number of 1s).	From the winning
	    positions it is possible to move to at least one losing:
					
- if xor of the sizes of the piles is not 0 we can change it to 0 by finding the left most column where the number 
  of 1s is odd, changing one of them to 0 and then by changing 0s or 1s on the right side of it to gain even number 
  of 1s in every column.	
*/

#include<iostream>
using namespace std;
int main()
{
	int a,n,w;
	while(cin>>n && n)
	{
		w = 0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			w = w xor a;
		}
		if(w)	cout<<"Yes\n";
		else	cout<<"No\n";
	}
}
