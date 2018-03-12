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
    string s;
    set <string> S;
    while(getline(cin,s))
    {
        int length = s.length();
        string word;
        int i;
        rep(i,length)
        {
            if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122)
            {
                if(s[i]>=65 && s[i]<=90)
                {
                    s[i]+=32;
                }
                word+=s[i];
            }
            else
            {
                if(word!="")
                    S.insert(word);
                word="";
            }
        }
        if(word!="")
            S.insert(word);
    }
    set <string>::iterator it;
    for(it=S.begin();it!=S.end();it++)
    {
        cout<<*it<<"\n";
    }
}

int main()
{
    //fastio;
    //filein;fileout;
    C_Enigma();

    return 0;
}
