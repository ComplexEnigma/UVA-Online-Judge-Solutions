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
    map < string, pair <int,int> > M;
    int N = _I();
    //getchar();
    
    int d,m,y;
    int maximum , minimum;
    int i;
    string s;
    
    rep( i , N )
    {
        cin>>s;

        d = _I();
        m = _I();
        y = _I();
        getchar();
        if( i == 0 )
        {
            maximum = y;
            minimum = y;
        }
        if( y < minimum)
            minimum = y;
        if( y > maximum)
            maximum = y;
        M[s] = make_pair( ((m-1)*30 + d),y);
    }
    
    map <string, pair<int,int> >::iterator it;
    
    int max_age = 0;
    int min_age = 400;
    string name1,name2;

    for( it=M.begin(); it!=M.end(); it++)
    {

        if( it->second.second == minimum)
        {
            if(it->second.first < min_age )
            {
                min_age = it->second.first;
                name1 = it->first;
            }
        }
        if( it->second.second == maximum )
        {

            if( it->second.first > max_age )
            {

                max_age = it->second.first;
                name2 = it->first;
            }
        }
    }
    cout << name2 <<endl;
    cout << name1 <<endl;
}

int main()
{
    //fastio;
    //filein;//fileout;
    C_Enigma();

    return 0;
}
