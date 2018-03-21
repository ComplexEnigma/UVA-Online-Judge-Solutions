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

int n;
double c[1010];

void PreCall()
{

}

void C_Enigma()
{
    //PreCall();
    while ( 1 )
    {
        scanf("%d", &n);
        if(n == 0) break;
        double avg = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%lf", &c[i]);
            avg += c[i];
        }
        avg = avg / n;
        double pos = 0, neg = 0;
        for(int i = 0; i < n; i++)
        {
            double v = (long) ((c[i] - avg) * 100.0) / 100.0;
            if(v > 0) pos += v;
            else neg += v;
        }
        neg = -neg;
        printf("$%.2f\n", neg > pos? neg : pos);
    }
}

int main()
{
    //fastio;
    //filein;
    //fileout;
    C_Enigma();

    return 0;
}
