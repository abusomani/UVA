#include<stdio.h>
#include<string.h>
int main()
{
	int f[101];
	int a,n;
	while(1)
	{
		scanf("%d",&n);
		bool flag = 1;
		if(!n)		break;
		memset(&f,0,sizeof(f));
		for(int i=0;i<n;i++)
			scanf("%d",&a),
			f[a]++;
		for(int i=1;i<=101;i++)
		{
			for(int j=0;j<f[i];j++)
			{
				if(flag)
					printf("%d",i), 	flag = 0;
				else
					printf(" %d",i);
			}
		}
		printf("\n");
	}
}
