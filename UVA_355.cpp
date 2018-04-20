#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector <ll> v;
map <int,vector<ll> > dp;
vector <char> temp;

void mypow()
{
    dp[2].push_back(1);dp[5].push_back(1);dp[8].push_back(1);dp[11].push_back(1);
    dp[3].push_back(1);dp[6].push_back(1);dp[9].push_back(1);dp[12].push_back(1);
    dp[4].push_back(1);dp[7].push_back(1);dp[10].push_back(1);dp[13].push_back(1);
    dp[14].push_back(1);dp[15].push_back(1);dp[16].push_back(1);
    for(int i=1;i<=15;i++)
    {
        for(int j=2;j<=16;j++)
        {
            dp[j].push_back( dp[j][i-1] * j );
        }
    }
}

bool validate(string s, int base)
{
    v.clear();
    int len = s.length();
    for(int i=0;i<len;i++)
    {
        if( s[i] >=65 )
            v.push_back(s[i]-55);
        else
            v.push_back(s[i]-48);

        if( v[i] >= base )
             return false;
    }
    return true;
}

string add( string num1, string num2)
{
    vector <char> res;
    int len1 = num1.length();
    int len2 = num2.length();
    int len = len1 > len2 ? len1 : len2;
    reverse(num1.begin() , num1.end());
    reverse(num2.begin() , num2.end());
    int carry = 0;
    for( int i=0; i<len; i++)
    {
        int sum = 0;
        if( i < len1)
            sum+= num1[i] - '0';
        if( i < len2)
            sum+= num2[i] - '0';
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        res.push_back( sum + 48 );
    }
    if( carry != 0 )
        res.push_back(carry + 48);
    string ans(res.rbegin(),res.rend());
    return ans;
}

string toBase( string num, int base)
{

    vector <char> res;
    if( num == "0")
        return "0";
    while( num!="0" )
    {
        vector <char> n;
        int rem = 0;
        int mod = 0;
        string tm_n = num;
        int flag = 0;
        int len = num.length();
        if( len <15 )
        {
            ll no = 0;
            for(int i=0;i<len;i++)
                no = (no*10) + num[i] - 48;
            while( no!=0 )
            {
                if( no%base < 10)
                    res.push_back( no%base + 48);
                else
                    res.push_back( no%base + 55);
                no /= base;
            }
            string ans(res.rbegin(),res.rend());
            return ans;
        }
        for(int i=0; i<len; i++)
        {
            rem = rem * 10;
            rem += (num[i] - 48) ;
            rem = rem % base;
            mod = mod * 10;
            mod += tm_n[i] - 48;

            if( mod < base)
            {
                continue;
            }
            n.push_back( mod/base + 48 );
            flag = 1;
            mod = (mod % base);
        }

        if(rem < 10)
        {
            res.push_back( rem + 48 );
        }
        else
        {
            res.push_back( rem + 55 );
        }
        if( flag == 0 )
                break;
        string tmp(n.begin(),n.end());
        num = tmp;
    }
    string ans(res.rbegin(),res.rend());
    return ans;
}

string toDec( string num, int base)
{
    int len = num.length();
    string n = "0";
    int j = 0;
    for( int i=len-1; i>=0; i-- )
    {
        ll t =  v[i]  * dp[base][j];
        string b = to_string( t );
        n = add( n, b );
        j ++;
    }
    return n;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int current_base;
    mypow();
    while( scanf("%d",&current_base) == 1)
    {
        int base;
        scanf("%d",&base);
        string number;
        getchar();
        cin >> number;

        if(!validate( number, current_base ) )
        {
            cout << number <<" is an illegal base "<< current_base<<" number\n";
        }
        else
        {
            string n = number;
            number = toDec( number, current_base);
            // cout << number << endl;
            number = toBase( number , base );
            cout << n <<" base "<< current_base <<" = "<<number<<" base "<< base << "\n";
        }
    }
    return 0;
}
