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
    int d,np,h;
    while(t--)
    {
        scanf("%d %d",&d,&np);
        vector <int> a(d+1);
        memset(&a[0],d+1,0);

        int c=0;
        for(int i=1;i<=np;i++)
        {
            scanf("%d",&h);
            int j=h;
            while(j<=d)
            {
                if(j%7==6 || j%7==0)
                    a[j]=0;
                else
                {
                    if(a[j]==0)
                    {
                        a[j]=1;
                        c++;
                    }
                }
                j=j+h;
            }
        }
        /*for(int i=1;i<=d;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;*/
        printf("%d\n",c);
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
