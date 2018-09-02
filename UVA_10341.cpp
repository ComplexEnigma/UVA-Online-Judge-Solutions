#include<bits/stdc++.h>
using namespace std;

double p, q, r, s, t, u;
#define inv 1e9

double calc( double x )
{
    return p*exp( -x ) + q * sin( x ) + r*cos( x ) + s * tan( x ) + t * x * x + u;
}

double bs()
{
    double l = 0, h = 1.0;
    int c = 35;
    double m;
    while( c )
    {
        m = ( l + h ) / 2;
        double value = calc( m );

        if( value - (int)value == 0 )
        {
            return m;
        }
        else if( value<0 )
            h = m;
        else
            l = m;
        c--;
    }

    return m;
}

int main()
{

    while( scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)==6)
    {
        double ans = bs();

        if( p*exp(-1) + q*sin(1) + r*cos(1) + s*tan(1) + t + u > 1e-9 || p + r + u < 0)
        {
            printf("No solution\n");
            continue;
        }
        else
        {
            printf("%0.4lf\n", ans );
        }
    }
    return 0;
}
