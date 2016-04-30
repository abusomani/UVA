#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
int main()
{
	int n,k,a;
	long long sum;
	multiset<int> st;
	multiset<int>:: iterator p;
	while(1)
	{
		scanf("%d",&n);
		sum = 0LL;
		if(!n)		break;
		for(int i=0;i<n;i++)
		{
			cin>>k;
			for(int i=0;i<k;i++)
				scanf("%d",&a),
				st.insert(a);
				
			p = st.end();							//  instead of using p and subtracting 1 we can use rbegin
			sum +=  *(--p) - *(st.begin());			// i.e. statement - sum += *(st.rbegin()) - *(st.begin())
			st.erase(st.begin());
			st.erase(p);
		}
		printf("%lld\n",sum);
		st.clear();
	}
}
