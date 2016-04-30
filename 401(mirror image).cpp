#include<bits/stdc++.h>
using namespace std;
bool palin , mirror;
char mr[256];
void chk(string str)
{
	int l = str.length();
	palin = mirror = 1;
	for(int i=0;i<l/2;i++)
	{
		if(str[i] != str[l-i-1])
			palin = 0;
		if(mr[str[i]] != str[l-i-1])
			mirror = 0;
	}
	if(l&1 && mr[str[l/2]] != str[l/2])
		mirror = 0;
}
int main()
{
	int cnt = 0;
	memset(&mr,0,sizeof(mr));
	mr['A'] = 'A';		mr['E'] = '3';
	mr['H'] = 'H';		mr['I'] = 'I';
	mr['L'] = 'J';		mr['J'] = 'L';
	mr['M'] = 'M';		mr['O'] = 'O';
	
	mr['S'] = '2';		mr['T'] = 'T';
	mr['U'] = 'U';		mr['V'] = 'V';
	mr['W'] = 'W';		mr['X'] = 'X';
	mr['Y'] = 'Y';		mr['Z'] = '5';
	
	mr['1'] = '1';		mr['2'] = 'S';
	mr['3'] = 'E';		mr['5'] = 'Z';
	
	mr['8'] = '8';	
	
	int k;	string str;
	set<string> st;
	while(cin>>str)
	{
		mirror = palin = 0;
		int cnt = 0;
		chk(str);
		cout<<str;
		if(palin && mirror)
			cout<<" -- is a mirrored palindrome.";
		else if(palin && !mirror)
			cout<<" -- is a regular palindrome.";
		else if(!palin & mirror)
			cout<<" -- is a mirrored string.";
		else
			cout<<" -- is not a palindrome.";
		cout<<endl<<endl;
	}
}
