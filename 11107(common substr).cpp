// uva 11107

#include<bits/stdc++.h>
#define M 26
using namespace std;
bool flag = 1;
struct trie
{
	trie* child[M+1];
	int count;
	int depth;
};
trie* root;

int idx(char c)
{
	if(c == '$')
		return M;
	else
		return c - 'a';
}

trie* newnode()
{
	trie* temp = new trie();
	temp->count = 1;
	for(int i=0;i<=M;i++)
		temp->child[i] = NULL;
	return temp;
}
void insert_in_trie(string str)
{
	int l = str.length();
	trie* temp = root;
	for(int i=0;i<l;i++)
	{
		if(temp->child[idx(str[i])] == NULL)
		{
			temp->child[idx(str[i])] = newnode();
		}
//		else
//			temp->child[idx(str[i])]->count++;
	}
}
void insert(string str)
{
	trie* temp = root;
	int l = str.length();
	flag ^= 1;
	for(int i=0;i<l;i++)
	{
		insert_in_trie(str.substr(i));	
	}
}
int main()
{
	int n;
	string str;
	string dollar = "$";
	while(cin>>n && n)
	{
		root = newnode();
		root->depth = 0;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			str += dollar;
			insert(str);
		}
		root = NULL;
	}
}
