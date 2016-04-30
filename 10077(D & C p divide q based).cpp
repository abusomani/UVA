#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct node
{
	ii left,right,mid;
};
int main()
{
	int m,n;		ii p;
	string str;
	while(1)
	{
		node start;		
		start.left.first = 0;		start.left.second = 1;
		start.mid.first = 1;		start.mid.second = 1;
		start.right.first = 1;		start.right.second = 0;
		cin>>m>>n;
		str = "";
		if(m==1 && n==1)		break;
		p = ii(m,n);
		
		while(1)
		{
			//cout<<start.mid.first<<" / "<<start.mid.second<<endl;
		 	if(m*start.mid.second > n*start.mid.first)
			{
				str += 'R';
				start.left = start.mid;
				start.mid.first  += start.right.first;
				start.mid.second += start.right.second;
			}
			else if(m*start.mid.second < n*start.mid.first)
			{
				str += 'L';
				start.right = start.mid;
				start.mid.first  += start.left.first;
				start.mid.second += start.left.second;
			}
			else
			{	cout<<str<<endl;		break;	 }
		}
	}	
}
