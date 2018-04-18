#include<bits/stdc++.h>
using namespace std;

int MAX;
vector <string> result;

void precall()
{
    int carry = 0;
    result.resize(1001);
    string num1, num2;
    num1 = "1", num2 = "2" ;
    MAX = 2;
    result[0] = "1", result[1] = "1";
    while( MAX<=1000 )
    {
        int len1 = num1.length();
        int len2 = num2.length();

        vector <char> temp;
        int index = 0;
        int current = 0;
        int carry = 0;

        for( int i=len2-1; i>=0; i-- )
        {
            int sz = temp.size();

            for( int j=len1-1; j>=0; j-- )
            {

                int sum = ( num2[i] - 48 ) * (num1[j] - 48 );

                if( current < sz )
                {
                    int pr = temp[current] - 48;
                    temp[current] = ( (temp[current] - 48 ) + sum + carry ) % 10;
                    temp[current] += 48;
                    carry = ( pr + sum + carry ) / 10;

                }
                else
                {

                    temp.push_back( (sum+carry)%10 + 48 );
                    carry = ( sum + carry ) / 10;
                    sz ++ ;

                }
                current ++ ;
            }
            index ++;
            while(carry!=0)
            {

                if( current< sz)
                {

                    temp[current] = ((temp[current] - 48 ) + carry ) % 10;

                    carry = ((temp[current] - 48 ) + carry) / 10;
                    temp[current] += 48;
                    current ++ ;
                    continue;
                }
                else
                    temp.push_back(carry+48);
                carry = 0;
            }
            current = index;
        }
        int sz = temp.size();

        while(carry!=0)
        {
            if( current< sz)
            {
                temp[current] = ((temp[current] - 48 ) + carry ) % 10;
                temp[current] += 48;
                carry = ((temp[current] - 48 ) + carry) / 10;
                current ++ ;
                continue;
            }
            else
                temp.push_back(carry+48);
            carry = 0;
        }
        string restemp(temp.rbegin(),temp.rend());

        result[MAX] = restemp;
        num1 = restemp;
        temp.clear();
        MAX ++;
        num2 = to_string(MAX);
    }
}

int main()
{
    int n;

    precall();
    while( scanf("%d",&n) == 1 )
    {
        cout << n << "!" << "\n" << result[n] << "\n";
    }
    return 0;
}
