#include<bits/stdc++.h>
using namespace std;

vector <string> v;

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

void func()
{
    v.push_back("0");v.push_back("1");v.push_back("1");
    for(int i=3;i<=5000;i++)
    {
        v.push_back( add(v[i-1] , v[i-2] ));
    }
}

int main()
{
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    func();
    int n;
    while( scanf("%d",&n) == 1 )
    {
        cout << "The Fibonacci number for " << n <<" is " << v[n] << endl;
    }
    return 0;
}
