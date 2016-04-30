#include<bits/stdc++.h>
using namespace std;
int gcd(int m, int n)     	
{
   int  r;                
   while (n != 0) 
   {      
      r = m % n;          
      m = n;            
      n = r;
   }                      
   return m;              
}
int nod(int n)
{
	int num = 0;
	while(n)
	{
		num++;
		n/=10;
	}
	return num;
}
void print(int a,int b)
{
	bool minus = 0;		int k=0;
	if(a<0)	{	minus = 1;	k = 2; 		a=-a;	}
	int c = 0;
	if(a>b)
	{
		c = a/b;
		a = a%b;
	}
	
	printf("%*d\n",k+nod(c)+nod(b),a);
	if(k==2)	cout<<"- ";
	if(c)	{	cout<<c;	}
	for(int i=0;i<nod(b);i++)	cout<<"-";
	cout<<endl;
	printf("%*d\n",k+nod(c)+nod(b),b);
	
}
int main()
{
	int n,a,sum,g;
	for(int j=1;1;j++)
	{
		cin>>n;	
		sum = 0;
		if(!n)	break;
		for(int i=0;i<n;i++)
		{	
			cin>>a;
			sum+=a;
		}
		cout<<"Case "<<j<<":\n";
		if(sum%n==0)
		{
			if(sum<0)
				cout<<"- "<<-sum/n<<endl;
			else
				cout<<sum/n<<endl;
		}
		else
		{
			g = gcd(abs(sum),n);
			sum = sum/g;
			n = n/g;
			print(sum,n);
		}
	}
}
