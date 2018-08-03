#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1000007;
int main()
{
    int t;
    scanf("%d",&t);
    int cases = 1;
    while(t--)
    {
        ll k , c , n , a;
        scanf("%lld %lld %lld %lld",&k,&c,&n,&a);
        vector <ll> num , v;
        num.push_back( a );

        int j = 0;
        for(int i=1;i<n;i++)
        {
            int b = ( num[i-1] % mod * k % mod ) % mod;
            b = ( b % mod + c % mod ) % mod;
            b %= mod;
            num.push_back( b );
            //sum += num[i] - num[i-1];
        }
        //cout << sum << endl;
        /*cout << sum << endl;*/
        sort(num.begin(),num.end());

        ll temp = 0;
        ll sum = 0;
        ll cs = 0;

        for(int i=0; i<n; i++)
        {
            v.push_back( i*num[i] - cs);
            if(v[j]<0)
                v[j] = abs(v[j] );
            cs += num[i];
            //cout << num[i] << " - > " << v[j] << endl;
            sum += v[j];
            j++;
        }
        /*for(int i=0; i<n; i++)
        {
            for(int k=i+1;k<n;k++)
                temp += abs( num[i] - num[k] );
        }
        cout << endl <<sum << " " << temp << " diff = " << abs(temp-sum) << endl;*/
        printf("Case %d: %lld\n", cases++, sum);
    }
    return 0;
}
