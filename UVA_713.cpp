#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    int n;
    scanf("%d",&n);
    getchar();
    int i = 0;
    for(int i=0;i<n;i++)
    {
        vector <char> num1, num2;
        string n1 , n2;
        cin >> n1 >> n2;
        reverse(n1.begin(),n1.end());
        reverse(n2.begin(),n2.end());
        int len1 , len2;
        len1 = n1.length();
        len2 = n2.length();
        bool flag = false;
        for(int j = 0; j<len1; j++)
        {
            if(!flag && n1[j]=='0')
            {
                continue;
            }
            else
            {
                flag = true;
                num1.push_back(n1[j]);
            }

        }
        flag = false;
        for(int j = 0; j<len2; j++)
        {
            if(!flag && n2[j]=='0')
            {
                continue;
            }
            else
            {
                flag = true;
                num2.push_back(n2[j]);
            }
        }

        len1 = num1.size();
        len2 = num2.size();

        vector <char> v;

        if(len1>=len2)
        {
            int j , k = len2-1;
            int carry = 0, sum = 0;
            for( j=len1-1 ; j>=0; j--)
            {

                sum = num1[j] - '0';
                sum += carry;
                if( k >= 0 )
                {
                    sum += num2[k] - '0';
                }

                k--;
                if( sum > 9 )
                {
                    carry = sum/10;
                    sum = sum % 10;
                }
                else
                    carry = 0;

                v.push_back(sum+'0');
            }
            if(carry)
                v.push_back(carry + '0' );
        }
        else
        {
            int j , k = len1 - 1;
            int carry = 0, sum = 0;
            for( j=len2-1 ; j>=0; j--)
            {
                sum = num2[j] - '0';
                sum += carry;
                if( k >= 0 )
                {
                    sum += num1[k] - '0';
                }
                k--;
                if( sum > 9 )
                {
                    carry = sum/10;
                    sum = sum % 10;
                }
                else
                    carry = 0;

                v.push_back(sum+'0');
            }
            if(carry)
                v.push_back(carry + '0' );
        }

        auto it = v.begin();
        while(it!=v.end())
        {
            if(*it=='0'){
                it++;
                continue;
            }
            else
                break;
        }
        string res(it,v.end());
        cout << res << "\n";
    }
    return 0;
}
