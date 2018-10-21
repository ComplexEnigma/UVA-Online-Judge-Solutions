#include<bits/stdc++.h>
using namespace std;

long long Combination( long long n, long long r )
{
        long long int ans = 1;

        if( n-r < r )
        {
                r = n- r;
        }

        for(long long int i=1; i<=r; i++ )
        {
                        ans *= n;
                        ans/=i;

                        n--;
        }

        return ans;
}

int main()
{
        
        long long int n , r;
        while( scanf("%lld %lld" , &n, &r )==2 && n!=0 && r!=0 )
        {
                long long ans = Combination( n ,  r );

                printf("%lld things taken %lld at a time is %lld exactly.\n" ,n, r, ans );
        }
        return 0;
}
