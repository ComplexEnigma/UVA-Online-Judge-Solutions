#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    getchar();
    int cases= 1;
    while(t--)
    {
        if(cases>1)
            printf("\n");
        map <string,int> M;
        string s;
        int cnt = 0;
        int counter = 0;
        while(getline(cin,s))
        {
            //cout << s << endl;
            if(s.length()==0 && cnt>1)
            {
                //cout << "yes" << "\n";
                break;
            }
            else if(s.length()>0)
            {
                M[s] ++;
                counter ++;
                cnt++;
            }
        }
        map<string,int>::iterator it;
        for(it=M.begin(); it!=M.end(); it++)
        {
            cout << it->first << " ";
            printf("%0.4lf\n",((long long)(it->second)/(double)counter)*100);
        }
        cases ++;
    }
    return 0;
}
