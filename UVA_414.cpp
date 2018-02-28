#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    while(cin>>n)
    {
        getchar();
        if(n==0)
            break;
        vector <int> c(n);
        for(int i=0;i<n;i++)
        {
            getline(cin,s);
            for(int j=0;j<s.length();j++)
            {
                if(s[j]==32)
                {
                    c[i]++;
                }
            }
        }
        sort(c.begin(),c.end());
        int sub=c[0];
        int counter=0;
        for(int i=0;i<c.size();i++)
        {
            counter=counter+c[i]-sub;
        }
        cout<<counter<<endl;
        counter=0;
        c.clear();
    }
    return 0;
}
