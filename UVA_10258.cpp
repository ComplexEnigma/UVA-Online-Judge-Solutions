#include<bits/stdc++.h>
using namespace std;
vector <int> solve;
vector <int> penalty;
vector <int> T;
map<int,vector<int> > Q, L;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    getchar();
    int cases = 1;
    while(cases<=n)
    {
        if(cases>1)
            printf("\n");
        /*** Clear ***/
        Q.clear();
        L.clear();
        penalty.clear();
        solve.clear();
        T.clear();

        penalty.resize(101);
        solve.resize(101);

        for(int i=1; i<=101; i++)
        {
            Q[i].resize(11);
        }

        string s;
        int cnt = 1;

        while(getline(cin,s))
        {
            if(s.length()==0 && cnt>1)
            {
                //cout << "Y" << cnt << endl;
                break;
            }
            int team = 0, prb = 0, time = 0;
            char ver;
            int in = 1;
            int len = s.length();
            for(int i=0; i<len; i++)
            {
                if(s[i]==32)
                {
                    in++;
                    continue;
                }
                if(in==1)
                {
                    team = team * 10;
                    team += s[i] - 48;
                }
                else if(in==2)
                {
                    prb = prb * 10;
                    prb += s[i] - 48;
                }
                else if(in==3)
                {
                    time = time * 10;
                    time += s[i] - 48;
                }
                else
                {
                    ver = s[i];
                }
            }
            //cout << "team = " << team << " prob = " << prb << " time = " << time << " ver = " << ver << endl;
            if(ver=='C' || ver=='I' || ver=='R' || ver=='U' || ver=='E')
            {
                if(find(T.begin(),T.end(),team)==T.end())
                    T.push_back( team );
            }
            if(ver=='C')
            {
                //cout << "team = " << team << " penalty = " << penalty[team] << " prb = " << prb << endl;
                if(find(L[team].begin(),L[team].end(),prb)==L[team].end())
                {
                    penalty[team] += Q[team][prb] + time;
                    solve[team] ++;
                    L[team].push_back(prb);
                }
                Q[team][prb] = 0;
            }
            if(ver=='I')
            {
                Q[team][prb] += 20;
            }
            cnt ++;
        }
        int sz = T.size();
        //cout << "Size = " << sz << endl;
        for(int i=0; i<sz; i++)
        {
            for(int j=i+1; j<sz; j++)
            {
                if(solve[T[j]]>solve[T[i]])
                {
                    swap(T[i],T[j]);
                }
                else if(solve[T[j]]==solve[T[i]])
                {
                    if(penalty[T[j]]<penalty[T[i]])
                    {
                        swap(T[i],T[j]);
                    }
                    else if(penalty[T[i]]==penalty[T[j]])
                    {
                        if(T[j]<T[i])
                            swap(T[i],T[j]);
                    }
                }
            }
        }
        for(int i=0; i<sz; i++)
        {
            printf("%d %d %d\n",T[i],solve[T[i]],penalty[T[i]]);
        }
        cases ++;
    }
    return 0;
}
