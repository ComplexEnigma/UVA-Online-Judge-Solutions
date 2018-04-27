/*
*   Created By : nomyspy
*   Date :
*   Complexity:
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    vector <char> F, R;
    vector <string> temp;
    string s;
    while(getline(cin,s))
    {
        F.clear();
        R.clear();
        temp.clear();
        int len = s.length();
        int op = 1;
        for(int i=0; i<len; i++)
        {
            if( op==1 )
            {
                if(s[i]!='[' && s[i]!=']')
                {
                    R.push_back(s[i]);
                }
            }
            else
            {
                if(s[i]!='[' && s[i]!=']')
                {
                    F.push_back(s[i]);
                }
            }
            if(s[i]==']')
            {
                op = 1;
                string ts(F.begin(),F.end());
                if(ts.length()!=0)
                    temp.push_back(ts);
                F.clear();
            }
            else if( s[i]=='[')
            {
                op = 2;
                string ts(F.begin(),F.end());
                if(ts.length()!=0)
                    temp.push_back(ts);
                F.clear();
            }
        }
        string ts(F.begin(),F.end());
        if(ts.length()!=0)
            temp.push_back(ts);
        for(auto it=temp.rbegin(); it!=temp.rend(); it++)
        {
            cout << *it;
        }
        string RR(R.begin(),R.end());
        cout << RR << endl;
    }
    return 0;
}
