/***
         _______________________________

             MD. SYMON HASAN SHOHAN
             UNIVERSITY OF ASIA PACIFIC
             isymonhs@gmail.com
         _______________________________
*/
#include<bits/stdc++.h>
using namespace std;

char s[105];

void solve()
{
    int g,n;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        getchar();
        cin>>s;
        int len=strlen(s);
        g=len/n;

        for(int i=0;i<len;i+=g)
        {
            for(int j=i+g-1;j>=i;j--)
            {
                printf("%c",s[j]);
            }
        }
        printf("\n");
    }

}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
    return 0;
}
