#include<bits/stdc++.h>
using namespace std;
struct card
{
	char s,r;
};
list<stack<card> > v;
list<stack<card> >:: iterator itr(const list<stack<card> >:: iterator p,int i)
{
	list<stack<card> >:: iterator a = p;
	if(i==3)
		a------;
	else
		a--;
	return a;
}

bool equal(const list<stack<card> >:: iterator p ,int i)
{
	card a = p->top();	
	card b = itr(p,i)->top();
	if(a.s==b.s || a.r==b.r)
		return 1;
	return 0;
}

int main()
{
	char a[3];
	card temp;	
	bool flag = 0;
	stack<card> t;
	list<stack<card> >::iterator p;
	bool exit = 0;
	while(1)
	{
		flag = 1;
		for(int i=0;i<52;i++)
		{
			cin>>a;
			if(a[0]=='#')	{	exit = 1;	break;	}
			temp.s = a[0];	temp.r = a[1];	
			stack<card> t;
			t.push(temp);
			v.push_back(t);
		}
		if(exit)	break;
		while(flag)
		{
			flag = 0;
			int i;
			for(p=v.begin(),i=0;p!=v.end();i++,p++)
			{
				if(i>=3	&& equal(p,3))
				{
					itr(p,3)->push(p->top());
					p->pop();
					if(p->empty())
						v.erase(p);
					flag = 1;
					break;
				}
				if(i>=1 && equal(p,1))
				{
					itr(p,1)->push(p->top());
					p->pop();
					if(p->empty())
						v.erase(p);
					flag = 1;
					break;
				}
			}
		}
		if(v.size()>1)		cout<<v.size()<<" piles remaining: ";
		else				cout<<v.size()<<" pile remaining: ";
		p = v.begin();
		while(p!=v.end())
		{
			cout<<p->size()<<" ";
			p++;
		}
		cout<<endl;
		v.clear();
	}
}
