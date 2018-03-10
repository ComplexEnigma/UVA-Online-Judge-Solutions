/***
         _______________________________

             MD. SYMON HASAN SHOHAN
             UNIVERSITY OF ASIA PACIFIC
             isymonhs@gmail.com
         _______________________________
*/
#include<bits/stdc++.h>
using namespace std;

#define filein() freopen("input.txt","r",stdin)
#define file() {freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);}
#define fastio() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define GraphString map<string, vector<string> > G
#define GraphInt map<int,vector<int> > G
#define VisitedString map<string,int> visited
#define VisitedInt map<int,int> visited
#define PrevString map<string,string> previous
#define PrevInt map<int,int> previous

#define Size(x) x.size()
#define Front(x) x.front()
#define Pop(x) x.pop()
#define Push(x,y) x.push(y)
#define Empty(x) x.empty()
#define PresentInMap(x,y) x.count(y)
#define PB(x,y) x.push_back(y)
#define Clear(x) x.clear()
#define FillVector(x) fill(x.begin(),x.end(),-1)
#define CreateVectorInt(x) vector<int> x

void solve()
{
    int l;
    char a,prev='\0';
    vector <int> vr;
    vector <int> vd;

    while(scanf("%d",&l)==1 && l!=0)
    {
        int zflag=0;
        getchar();
        vr.clear();
        vd.clear();
        for(int i=0;i<l;i++)
        {
            scanf("%c",&a);
            //cout<<a<<endl;
            if(a=='Z')
                zflag=1;
            else if(a=='R')
                vr.push_back(i);
            else if(a=='D')
                vd.push_back(i);
        }
        if(zflag==1)
        {
            printf("0\n");
        }
        else{
            int sr=vr.size();
            int sd=vd.size();
            int m=5000005;
            for(int i=0;i<sr;i++)
            {
                for(int j=0;j<sd;j++)
                {
                    if(abs(vr[i]-vd[j])<m)
                        m=abs(vr[i]-vd[j]);
                }
            }
            printf("%d\n",m);
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}
