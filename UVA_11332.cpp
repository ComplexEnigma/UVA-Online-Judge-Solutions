#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,r,t,s,sum=0,sum1=0,sum2=0;
	while(1)
	{
		scanf("%d",&n);
		sum=0,sum1=0,sum2=0;
		if(n==0)
		{
			break;
		}
		while(n!=0)
		{
			r=n%10;
			sum=sum+r;
			n=n/10;
		}
		if(sum>9)
		{
			while(sum!=0)
			{
				t=sum%10;
				sum1=sum1+t;
				sum=sum/10;
			}
			if(sum1>9)
			{
			while(sum1!=0)
			{
				s=sum1%10;
				sum2=sum2+s;
				sum1=sum1/10;
			}
			printf("%d\n",sum2);
			}
			else
			{
				printf("%d\n",sum1);
			}
		
		}
		else
		{
		printf("%d\n",sum);
		}
	}
}