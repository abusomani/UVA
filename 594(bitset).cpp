#include<bits/stdc++.h>
using namespace std;
long convert(string& str)
{
	int l = str.length();
	long two = 1;		
	long num=0;
	for(int i = l-1;i>=1;i--)						// upto 31 length only
	{
		num += (str[i]-'0')*two;
		two = 2*two;
	}
	return num;
}

long twocomp(string &str)
{
	long n;
	bitset<32> b(str);
	b.flip();
	str = b.to_string();
	n = convert(str);
	n++;
	return -n;
}
string tobin(long num)
{
	string str = "";
	while(num)
	{
		str += (char)(num%2+'0');
		num /= 2;
	}
		
	int l = str.length();
	
	for(int i=0;i<l/2;i++)
		swap(str[i],str[l-i-1]);
	return str;
}
int main()
{
	long num,n;
	string str,str1,str2,str3,str4;
	bool flag = 0;
	while(cin>>num)
	{
		str = "";
		flag = 0;
		if(num<0)	flag = 1,	num = -num;
		str = tobin(num);
		bitset<32> b(str);						// appending 0s at starting using bitset (it automatic adds)
		str = b.to_string();
		if(flag)								// getting two's complement	for -ve
		{	
			cout<<str<<endl;
			b.flip();
			str = b.to_string();
			//cout<<str<<endl;
			n = convert(str);
			n++;
			str = tobin(n);
			int l = str.length();					// again making it to 32 size length
			for(int i=0;i<32-l;i++)
				str = '1'+str;
			
		}
		//cout<<str<<endl;
		str1 = str.substr(0,8);
		str2 = str.substr(8,8);
		str3 = str.substr(16,8);
		str4 = str.substr(24,8);
	
		str = str4 + str3 + str2 + str1;
		if(str[0]=='1')							// i.e. negative number
			n = twocomp(str);
		else
			n = convert(str);
		cout<<(flag?-num:num)<<" converts to "<<n<<endl;
	}
}
