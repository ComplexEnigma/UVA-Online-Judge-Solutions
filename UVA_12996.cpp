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
    int T = _I();
    int cases;
    REP(cases,1,T+1)
    {
        int N = _I();
        int L = _I();
        vector < int > plate;
        vector < int > capacity;
        int i;
        int total_mango = 0;
        rep(i,N)
        {
            int a = _I();
            total_mango+=a;
            PB(plate,a);
        }
        rep(i,N)
        {
            int a = _I();
            PB(capacity,a);
        }
        int flag = 0;
        if( total_mango > L )
        {
            flag = 1;
        }
        else
        {
            rep( i, N )
            {
                if( capacity[i]>= plate[i] )
                {
                    continue;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        printf("Case %d: ",cases);
        if(flag)
            puts("No");
        else
            puts("Yes");
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
