//	Ad hoc string problem

#include<bits/stdc++.h>
using namespace std;
double get(char c)
{
	if(c == 'm')	return 0.001;
	if(c == 'k')	return 1000;
	if(c == 'M')	return 1000000;
}
double atoi(string str)
{
	int l = str.length();
	double num = 0;		int ten = 10;
	bool dot = 1;
	for(int i=0;i<l;i++)
	{
		if(str[i] == '.')
		{ 	dot = 0;	continue;	}
		if(dot)
			num = num*10 + (int)str[i]-'0';
		else
		{
			num = num + (double)(str[i]-'0')/ten ;
			ten *= 10;
		}
	}
	return num;
}
int main()
{
	int t;	string p,u,i,str;
	string keep[3];			double x;		double num[3];
	p = "P=";   u = "U=";    i = "I=";
	char end[3] = {'W','V','A'};
	int pos[3];
	cin>>t;
	cin.ignore(100,'\n');
	for(int j=1 ; j<=t ; j++)
	{
		keep[0] = keep[1] = keep[2] = "";
		getline(cin,str);
		pos[0] = str.find(p);		pos[1] = str.find(u);		pos[2] = str.find(i);
		for(int i=0;i<3;i++)
		{
			if(pos[i] != -1)
			{
				for(int k=pos[i]+2;k<str.length() && str[k] != end[i];k++)
					keep[i] += str[k];
			}
		}
		for(int i=0;i<3;i++)
		{
			if(keep[i] != "")
			{
				if(keep[i][keep[i].length()-1] <'0'  ||  keep[i][keep[i].length()-1] >'9')
				{
					x = get(keep[i][keep[i].length()-1]);
					keep[i].erase(keep[i].end()-1);
					num[i] = atoi(keep[i])*x; 
				}
				else
					num[i] = atoi(keep[i]);
				
			//	cout<<num[i]<<endl;
			}
		}
		
		printf("Problem #%d\n",j);
		if(pos[0] == -1)
			printf("P=%.2fW",num[1]*num[2]);
		if(pos[1] == -1)
			printf("U=%.2fV",(double)num[0]/num[2]);
		if(pos[2] == -1)
			printf("I=%.2fA",(double)num[0]/num[1]);
		printf("\n\n");
	}
}
