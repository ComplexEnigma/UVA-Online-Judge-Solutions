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
    int n, m;

    while( scanf("%d %d",&n ,&m ) == 2 )
    {
        if(n==0 && m==0)
            break;

        vector <int> dragon;
        vector <pair<int,int> > knight;

        dragon.resize(n);

        for( int i=0 ;i<n; i++)
            dragon[i] = _I();

        for(int i=0; i<m; i++)
        {
            int a = _I();
            PB( knight, make_pair(a,0));
        }


        if( m < n)
        {
            printf("Loowater is doomed!\n");
            continue;
        }

        Sort(dragon);
        Sort(knight);

        int ans = 0, flag = 0;
        int temp_flag = 0;

        for(int i=0;i<n;i++)
        {
            int j = 0;
            while( j<m )
            {
                if( knight[j].second == 0 && knight[j].first >= dragon[i] && temp_flag == 0)
                {
                    //cout << knight[j].first << endl;
                    ans += knight[j].first;
                    knight[j].second = 1;
                    temp_flag = 1;
                }
                if(temp_flag)
                    break;
                j++;
            }
            if(temp_flag == 0)
            {
                flag = 1;
                break;
            }
            temp_flag = 0;
        }

        if(flag == 1)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n",ans);
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
