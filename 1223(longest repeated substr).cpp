#include <bits/stdc++.h>
#define M 26
using namespace std;
typedef pair<int,int> ii;
struct trie  
{	
	int count;
	int depth;
	trie* child[M+1];
};

trie* root;
int idx(char c)
{
	if(c == '$')
		return M; 
	return c - 'a';
}
int end,start;
trie* last;

void insert_in_trie(int st,char* str)
{
	int l = strlen(str);
	trie* temp = root;
	bool flag = 1;
	for(int i=0;i<l;i++)
	{
		if(temp->child[idx(str[i])] == NULL)
   		{	
		   	temp->child[idx(str[i])] = new trie();
   			temp->child[idx(str[i])]->count = 1;
   			
   			if(i >= end and flag)
			{
				if(i!=end)
				{
					end = i;	start = st;		 
					last = temp;
				}
				else
				{
					if(temp->count > last->count)
					{	 
						end = i;	start = st;	
						last = temp;	
					}
				}		
				flag = 0;
			}
   		
   			
			for(int j=0;j<=M;j++)	temp->child[idx(str[i])]->child[j] = NULL;
   		}
   		else
   			temp->child[idx(str[i])]->count++;	
   		temp = temp->child[idx(str[i])];
	}
}

void insert(char* str)
{
	int l = strlen(str);
	root = new trie();
	root->depth = 0;
	last = root;
	
	for(int j=0;j<=M;j++)	root->child[j] = NULL;
	for(int i=0;i<l;i++)
	{
		insert_in_trie(i,str+i);
	}
}
/*
BFS 
int deepest_node()
{
	trie* temp = root;
	int ans = 0;
	queue<trie*> q;
	trie* maxv = root;
	q.push(temp);
	while(!q.empty())
	{
		temp = q.front();		q.pop();
		for(int i=0 ; i<=M ; i++)
		{
			if(temp->child[i] != NULL)
			{
				temp->child[i]->depth = temp->depth + 1;
			
				if(temp->count>1 and  temp->depth > maxv->depth)
				{
					maxv = temp;
					ans = maxv->depth;
				}
			
			//	cout<<(char)(i+'a')<<" "<<temp->child[i]->count<<" "<<temp->child[i]->depth<<endl;
				q.push(temp->child[i]);
			}
		}
	}
	
	return ans;
}
*/
int main()
{
	int n;
	char str[6010];
	char dollar[] = "$";
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		strcat(str,dollar);
		insert(str);
		cout<<end<<endl;
		start = end = 0;
		root = NULL;
	}
}
