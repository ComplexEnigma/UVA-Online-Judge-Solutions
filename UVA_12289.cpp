/***
         _______________________________

             MD. SYMON HASAN SHOHAN
             UNIVERSITY OF ASIA PACIFIC
             isymonhs@gmail.com
         _______________________________
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define scd(x) scanf("%lf",&x)
#define scs(x) scanf("%s",x)

#define pfi(x) printf("%d",x)
#define pfs(x) printf("%s",s)
#define pfl(x) printf("%lld",x)
#define pfd(x) printf("%lf",x)
#define pfc(x) printf("Case %d: ",x)
#define ps printf(" ")
#define pn printf("\n")

#define FOR(i, s, n) for (int i = s; i <= (int)n; i++)
#define pb(x) push_back(x)

#define ppb(x) pop_back(x)
#define pf(x) push_front(x)
#define ppf(x) pop_front(x)
#define in(x,y) insert({x,y})
#define sv(a) sort(a.begin(),a.end()

void solve()
{
    int t;
    scanf("%d",&t);
    string s;
    while(t--)
    {
        cin>>s;
        if(s.length()==5)
            printf("3\n");
        else
        {
            if(s[0]=='o' && s[1]=='n' || s[0]=='o' && s[2]=='e' || s[1]=='n' && s[2]=='e')
                printf("1\n");
            else
                printf("2\n");
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}
