#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int T;
    int result=0;
    cin>>T;
    int n;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        int a=n;
        int s,an,ef;  //Size , Animal, Env Frnd
    for(int j=0;j<a;j++)
    {
        cin>>s;
        cin>>an;
        cin>>ef;
        result+=(s*ef);
    }
    cout<<result<<endl;
    result=0;
    }
    return 0;
}

