// Created By ComplexEnigma

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<utility>
using namespace std;

typedef long long ll;

#define filein() {freopen("input.txt","r",stdin);}
#define fileout() {freopen("output.txt","w",stdout);}

int _I() {int x;scanf("%d",&x);return x;}
ll _LL() {ll x;scanf("%lld",&x);return x;}
float _F() {float x;scanf("%f",&x);return x;}
double _LF() {double x;scanf("%lf",&x);return x;}

#define PB(x,y) x.push_back(y)
#define Clear(x) x.clear()
#define Resize(x) x.resize()
#define Fill(x,y) fill(x.begin(),x.end(),y)
#define Sort(x) sort(x.begin(),x.end())

int N;
int prime[40000];

void sieve()
{
    prime[0] = 1;
    prime[1] = 1;
    for( int i=4;i<40000;i+=2)
        prime[i] = 1;
    for(int i=3;i*i<40000;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=3*i;j<40000;j+=i)
                prime[j] = 1;
        }
    }
}

void C_Enigma()
{

    sieve();

    while(1)
    {
        N = _I();
        if( N == 0 )
            break;
        int counter = 0;
        for( int i = 2; i<=N/2; i++)
        {

            if(prime[i]==0 && prime[N-i]==0)
            {
                counter++;
            }
        }
        printf("%d\n",counter);
    }
}

int main()
{
    //filein();fileout();
    C_Enigma();

    return 0;
}
