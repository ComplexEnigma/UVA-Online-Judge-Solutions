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
int hashvalue(string a)
{
    long long int value=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>=65 && a[i]<=90)
        {
            int l=a[i]%64;
            value=value+l;
        }
        else if(a[i]>=97 && a[i]<=122)
        {
            int l=a[i]%96;
            value=value+l;
        }
    }
    return value;
}
int calculation(int a)
{
    int n=a;
    int sum=0;
    while(n>=10)
    {
        a=n;
        while(a!=0)
        {
            sum+=a%10;
            a/=10;
        }
        n=sum;
        sum=0;
    }
    return n;
}
void solve()
{
    string s1,s2;
    while(getline(cin,s1) && getline(cin,s2))
    {
        int r1=calculation(hashvalue(s1));
        int r2=calculation(hashvalue(s2));
        if(r2>r1)
            swap(r2,r1);
        double ans=(r2/(double)r1)*100;
        printf("%0.2lf %%\n",ans);
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
    return 0;
}
