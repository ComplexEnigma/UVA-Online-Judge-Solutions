#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,a,b,c,i;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a>b && a>c)
		{
			if(b>c)
			{
				printf("Case %d: %d\n",i,b);
			}
			else
			{
				printf("Case %d: %d\n",i,c);
			}
		}
		if(b>a && b>c)
		{
			if(a>c)
			{
				printf("Case %d: %d\n",i,a);
			}
			else
			{
				printf("Case %d: %d\n",i,c);
			}
		}
		if(c>b && c>a)
		{
			if(a>b)
			{
				printf("Case %d: %d\n",i,a);
			}
			else
			{
				printf("Case %d: %d\n",i,b);
			}
		}
	}
}
