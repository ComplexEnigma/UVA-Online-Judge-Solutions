#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int j=1;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        vector <int> v;
        int sum=0;
        int a;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            v.push_back(a);
            sum+=a;
        }
        sum/=n;
        a=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]>sum)
                a+=abs(sum-v[i]);
        }
        printf("Set #%d\n",j);
        printf("The minimum number of moves is %d.\n",a);
        j++;
        v.clear();
        printf("\n");
    }
    return 0;
}
