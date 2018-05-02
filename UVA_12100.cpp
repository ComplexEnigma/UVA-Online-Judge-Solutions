#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n, pos;
        queue <int> Q;
        vector <int> v, c;
        scanf("%d %d",&n,&pos);
        v.resize(n);
        c.resize(10);
        for(int i=0;i<n;i++)
        {
            Q.push(i);
            int a;
            scanf("%d",&a);
            c[a] ++;
            v[i] = a;
        }
        int j = 9;
        int counter = 0;
        while(j>v[pos])
        {
            while(c[j]!=0)
            {
                //cout << j << " = " << c[j] << endl;
                int a ;
                a = Q.front();
                Q.pop();
                if(v[a]==j){
                    //cout << a << " " << v[a] << endl;
                    c[j] --;
                    counter ++;
                }
                else
                    Q.push(a);
            }
            j--;
        }
        while(!Q.empty())
        {
            int a = Q.front();
            Q.pop();
            if(a==pos)
                break;
            else if(v[a]==v[pos])
                counter ++;
        }
        printf("%d\n",++counter);
    }
    return 0;
}
