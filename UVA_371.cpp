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
#define MAX 100005
int counter;
int dp[(4*MAX)];

void PreCall(ll n)
{
    
    if(n==1)
    {
        return;
    }
    if(n%2==1)
    {
        counter++;
        n = 3*n+1;
        if(n%2==0)
        {
            counter++;
            n/=2;
        }
    }
    else
    {
        counter++;
        n/=2;
    }
    if(n<(4*MAX) && dp[n]!=0 && n!=1)
    {
        counter+=dp[n];
        return;
    }
    PreCall(n);
}

void C_Enigma()
{
    int N, L;
    dp[1] = 3;
    while( scanf("%d %d",&N,&L)==2 )
    {

        if( N==0 && L==0)
            break;
        if(N>L)
        {
            swap(N,L);
        }
        
        int maximum = 0,number;
        for (int i= N;i<=L;i++)
        {
            if(i<(4*MAX) && dp[i] !=0 )
            {
                
                counter = dp[i];
            }
            else
            {
                counter = 0;
                PreCall((ll)i);
                if(i<4*MAX)
                    dp[i] = counter;
            }
            
            if(counter > maximum)
            {
                maximum = counter;
                number = i;
            }
        }

        printf("Between %d and %d, %d generates the longest sequence of %d values.\n",N,L,number,maximum);
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
