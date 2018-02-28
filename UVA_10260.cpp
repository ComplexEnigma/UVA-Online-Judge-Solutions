// Created By ComplexEnigma

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
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
    map <char,int> m;
    m['B']=m['F']=m['P']=m['V']=1;
    m['C']=m['G']=m['J']=m['K']=m['Q']=m['X']=m['S']=m['Z']=2;
    m['D']=m['T']=3;
    m['L']=4;
    m['N']=m['M']=5;
    m['R']=6;

    char s[25];

    while(scanf("%s",&s)==1)
    {
        stack <char> S;
        ll n=(long long)m[s[0]];
        S.push(s[0]);
        for(int i=1;s[i]!='\0';i++)
        {
            if(m[S.top()]==m[s[i]])
                continue;
            else
            {
                if(m[S.top()]!=m[s[i]] && m[s[i]]!=0)
                {
                    //cout<<s[i]<<endl;
                    n=n*10+(long long)m[s[i]];
                    //cout<<n<<endl;
                }
                S.push(s[i]);
            }
        }
        if(n!=0)
            printf("%lld\n",n);
        else
            printf("\n");
    }
}

int main()
{
    //filein();fileout();
    C_Enigma();

    return 0;
}
