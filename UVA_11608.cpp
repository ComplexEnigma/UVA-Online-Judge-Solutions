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

int produce[13],required[13];

void C_Enigma()
{
    int s;
    int cases=0;
    while(scanf("%d",&s)==1)
    {
        if(s<0)
            break;

        for(int i=1;i<13;i++)
            produce[i]=_I();
        for(int i=1;i<13;i++)
            required[i]=_I();

        vector <int> v(13);
        printf("Case %d:\n",++cases);
        if(required[1]<=s){
            v[1]=1;
            s+=produce[1]-required[1];
            printf("No problem! :D\n");
        }
        else
        {
            v[1]=0;
            s+=produce[1];
            printf("No problem. :(\n");
        }
        for(int i=2;i<=12;i++)
        {
            if(required[i]<=s)
            {
                v[i]=1;
                s-=required[i];
                s+=produce[i];
            }
            else
            {
                v[i]=0;
                s+=produce[i];
            }
            if(v[i]==0)
                printf("No problem. :(");
            else
                printf("No problem! :D");
            printf("\n");
        }

    }
}

int main()
{
    //filein();fileout();
    C_Enigma();

    return 0;
}
