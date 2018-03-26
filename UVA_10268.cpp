// Author : ComplexEnigma
// Date :

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<utility>
using namespace std;

typedef long long ll;

#define filein        {freopen("input.txt","r",stdin);}
#define fileout     {freopen("output.txt","w",stdout);}
#define fastio      {ios_base::sync_with_stdio(false);cin.tie(NULL);}

#define PB(x,y) x.push_back(y)
#define Clear(x) x.clear()
#define Resize(x) x.resize()
#define Fill(x,y) fill(x.begin(),x.end(),y)
#define Sort(x) sort(x.begin(),x.end())
#define rep(i,n) for( i=0; i<n; i++)
#define REP(i,k,n) for( i=k; i<n; i++)
#define REPR(i,k,n) for( i=k; i>n; i--)

int _I() {int x;scanf("%d",&x);return x;}
ll _LL() {ll x;scanf("%lld",&x);return x;}
float _F() {float x;scanf("%f",&x);return x;}
double _LF() {double x;scanf("%lf",&x);return x;}


ll mypow(ll x,int n)
{
    int sum = 1;
    for(int i=1;i<=n;i++)
    {
        sum*= x;
    }
    return sum;
}

ll fastexpo(ll x,ll n)
{
    //cout << n << endl;
    if(n==0)
        return 1;
    if(n&1)
        return x*fastexpo(x*x,(n-1)/2);
    else
        return fastexpo(x*x,n/2);
}

void C_Enigma()
{
    ll x;
    while( scanf("%lld",&x) == 1)
    {
        getchar();
        char ch;
        ll num = 0;
        int minus_flag = 0;
        vector <ll> v;
        while(1)
        {
            //cout << num << endl;
            scanf("%c",&ch);

            if( ch == '\n')
            {
                if(minus_flag)
                    num = - num;
                PB(v,num);
                num = 0;
                minus_flag = 0;
                break;
            }

            if(ch=='-')
            {
                //cout << "mf " << endl;
                 minus_flag = 1;
                 continue;
            }
            else if(ch == 32)
            {
               // cout << "space" << endl;
                if(minus_flag)
                    num = - num;
                PB(v,num);
                num = 0;
                minus_flag = 0;
                continue;
            }
            else
            {
                //cout << "n a " << ch << endl;
                num = num*10 + ch-'0';
            }

            /*if(minus_flag)
            {
                num = -num;
                minus_flag = 0;
            }*/
        }

        ll sz = v.size();
        /*for( int i=0;i<sz;i++)
        {
            cout << v[i] << endl;
        }*/
        ll n = sz - 1;
        ll sum = 0;
        for( int i=0; i<sz ; i++)
        {
            //cout << n << endl;
            if(n==0)
            {
                //cout << "w" << endl;
                continue;
            }
            sum += v[i]*n*fastexpo(x,n-1);
            n--;
        }
        printf("%lld\n",sum);
    }
}

int main()
{
    //fastio;
    //filein;fileout;
    C_Enigma();

    return 0;
}
