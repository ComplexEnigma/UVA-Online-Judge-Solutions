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
    int n;
   // vector <ll> v1,v2,v3,v4;
    //ll m=99999999;
    //cout<<m<<endl;
    /*for(ll i=0;i<=m;i++)
    {
            if(((i%10)+(i/10))*((i%10)+(i/10))==i)
            {
                PB(v1,i);
            }
            if(((i%100)+(i/100))*((i%100)+(i/100))==i)
            {
                PB(v2,i);
            }
            if(((i%1000)+(i/1000))*((i%1000)+(i/1000))==i)
            {
                PB(v3,i);
            }
            if(((i%10000)+(i/10000))*((i%10000)+(i/10000))==i)
            {
                PB(v4,i);
            }
        }
//    cout<<3025%100<<3025/100<<endl;
    cout<<"2 -> ";
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl<<"4 -> ";
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl<<"6 -> ";
    for(int i=0;i<v3.size();i++)
    {
        cout<<v3[i]<<" ";
    }
    cout<<endl<<"8 -> ";
    for(int i=0;i<v4.size();i++)
    {
        cout<<v4[i]<<" ";
    }
    cout<<endl;
    */
    vector <string> v1,v2,v3,v4;
    // 2
    PB(v1,"00");PB(v1,"01");PB(v1,"81");
    // 4
    PB(v2,"0000");PB(v2,"0001");PB(v2,"2025");PB(v2,"3025");PB(v2,"9801");
    // 6
    PB(v3,"000000");PB(v3,"000001");PB(v3,"088209");PB(v3,"494209");PB(v3,"998001");
    //8
    PB(v4,"00000000"); PB(v4,"00000001"); PB(v4,"04941729"); PB(v4,"07441984");
    PB(v4,"24502500"); PB(v4,"25502500"); PB(v4,"52881984"); PB(v4,"60481729");
    PB(v4,"99980001");

    while(scanf("%d",&n)==1)
    {
        if(n==2)
        {
            for(int i=0;i<3;i++)
                cout<<v1[i]<<endl;
        }
        else if(n==4)
        {
            for(int i=0;i<5;i++)
                cout<<v2[i]<<endl;
        }
        else if(n==6)
        {
            for(int i=0;i<5;i++)
                cout<<v3[i]<<endl;
        }
        else
        {
            for(int i=0;i<9;i++)
                cout<<v4[i]<<endl;
        }
    }
}

int main()
{
    //filein();fileout();
    C_Enigma();

    return 0;
}
