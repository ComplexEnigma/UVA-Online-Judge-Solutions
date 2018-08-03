#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cases = 1;
    while( t-- )
    {
        ll a, b;
        scanf("%lld %lld",&a, &b);
        vector <int> b1, b2;
        ll temp1 = a, temp2 = b;
        int sz1 = 0, sz2 = 0;
        while( temp1>0 || temp2>0)
        {
            if(temp1!=0)
            {
                b1.push_back( temp1%2 );
                temp1/=2;
                sz1 ++;
            }
            if(temp2!=0)
            {
                b2.push_back( temp2%2 );
                temp2/=2;
                sz2 ++;
            }

        }

        ll ans_or = 0, ans_and = 0;
        ll diff = b - a;
        ll p = 1;
        //cout << sz1 << " " << sz2 << endl;
        for(int i=0;i<sz1;i++)
        {
            if(diff>p)
                ans_or += p;
            else{
                if(b1[i]!=b2[i])
                    ans_or += p;
                else
                    ans_or += b1[i] * p;
            }
            p*=2;
        }
        for(int i=sz1;i<sz2;i++){
            ans_or += p; p*=2;
        }
        if(b1==b2)
        {
            ans_or = a;
            ans_and = a;
        }
        else if(sz1==sz2)
        {
            int flag = 0;
            ll p = 1;
            for(int i=0;i<sz1;i++)
            {
                if(diff<p && b1[i]==b2[i])
                {
                    //cout << diff << " p = " << p << "b1 = " << b1[i] << "b2 = " << b2[i]<< endl;;
                    ans_and += b1[i]*p;
                }
                p*=2;
            }

        }
        else
        {
            ans_and = 0;
            //ans_or = pow(2, sz2-1);

        }
        printf("Case %d: %lld %lld\n",cases++, ans_or, ans_and);
    }
    return 0;
}
