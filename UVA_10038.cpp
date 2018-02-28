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
    int n;
    vector <int> v;
    int a;
    int p;
    while(scanf("%d",&n)==1)
    {
        v.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(i==0)
                p=a;
            else
            {
                v.push_back(abs(p-a));
                p=a;
            }
        }
        sort(v.begin(),v.end());
        int flag=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=i+1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
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
