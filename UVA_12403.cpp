#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int t,n;
    long long int sum=0;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        cin>>s;
        if(s=="donate"){
            scanf("%d",&n);
            getchar();
            sum+=n;
        }
        else
            printf("%lld\n",sum);

    }
    return 0;
}
