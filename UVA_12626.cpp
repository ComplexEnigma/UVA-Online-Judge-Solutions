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

void PreCall()
{

}

void C_Enigma()
{
    //PreCall();
    int N = _I();
    getchar();
    while( N--)
    {
        string s;
        getline(cin,s);
        int length = s.length();
        int i;
        int cm = 0, ca = 0, cr = 0, cg = 0, ci = 0, ct = 0;
        int pizza = 0;
        rep(i,length)
        {
            if(s[i]=='A')
                ca++;
            if(s[i]=='M')
                cm++;
            if(s[i]=='R')
                cr++;
            if(s[i]=='G')
                cg++;
            if(s[i]=='I')
                ci++;
            if(s[i]=='T')
                ct++;
            if(cm>=1 && ca>=3 && cr>=2 && cg>=1 && ct>=1 && ci>=1)
            {
                cm--;ca-=3;cr-=2;cg--;ct--;ci--;
                pizza ++;
            }
        }
        printf("%d\n",pizza);
    }
}

int main()
{
    //fastio;
    //filein;fileout;
    C_Enigma();

    return 0;
}
