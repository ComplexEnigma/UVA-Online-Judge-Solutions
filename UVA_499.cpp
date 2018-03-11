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
    string s;
    while( getline(cin,s))
    {
        map <char,int> m;
        int length = s.length();
        int maximum = 0;
        char ch;
        for(int i=0;i<length;i++)
        {
            if( (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))
            {
                m[s[i]]++;
                if(m[s[i]]>maximum)
                {
                    maximum = m[s[i]];
                }
            }
        }
        map <char,int>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second == maximum )
            {
                printf("%c",it->first);
            }
        }
        printf(" %d\n",maximum);
    }
}

int main()
{
    //filein();
    //fileout();
    C_Enigma();

    return 0;
}
