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


void C_Enigma()
{
    int t;
    t=_I();
    while(t--)
    {
        map <char,int> m;
        char c;
        int n;
        int a;
        n=_I();
        //getchar();
        while(n--)
        {
            scanf(" %c",&c);
            a=_I();
            m[c]=a;
        }
        int k;
        k=_I();
        getchar();
        ll cent=0;
        while(k--)
        {
            char s[10005];
            gets(s);
            for(int i=0;s[i]!='\0';i++)
            {
                if(m.count(s[i])==true)
                    cent+=m[s[i]];
            }
            //cout<<k<<endl;
        }
        double ans=cent/(double)100;
        printf("%0.2lf$\n",ans);
    }
}

int main()
{
    filein();fileout();
    C_Enigma();

    return 0;
}
