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
    int H,D,F;
    float U;
    while(1)
    {
        H = _I();
        U = _F();
        D = _I();
        F = _I();
        if( (ll)H==0 )
            break;
        int Day = 1;
        double factor = ( U*F)/(float)100;
        //cout << factor << endl;
        float initial_height = 0.0;
        bool flag = false;
        while(1)
        {
            /*if( U<0 )
            {
                flag = true;
                break;
            }*/
            //cout << "Day "<< Day << " : ";
            //cout << "  Can Climb " << U;
            //cout << "  Initial Height " << initial_height ;
            initial_height += U;
            //cout << "  Height After Climbing " << initial_height;
            if( U > 0 ){
                //cout << (U>0) <<endl;
                U -= factor;
            }
            if( initial_height > H)
                break;
            initial_height -= D;
            if( initial_height < 0 )
            {
                flag = true;
                break;
            }
            //cout << "  Height After Sliding " << initial_height;
            //cout << "\n\n";
            Day ++ ;
        }
        if(!flag)
            printf("success on day %d",Day);
        else
            printf("failure on day %d",Day);
        puts("");
    }
}

int main()
{
    //filein();fileout();
    C_Enigma();

    return 0;
}
