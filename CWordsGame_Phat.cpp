#include <bits/stdc++.h>

using namespace std;

FILE *fi=freopen("CWordsGame.inp","r",stdin);
FILE *fo=freopen("CWordsGame.out","w",stdout);

const int N=2e5+5;

int n[2],T=1,f[N];
map<string,int> m;
vector<int> a[2][N];
string b[2][N];
string smp[]={"Bi","Den"};

void nhap()
{
    string emp;
    m[emp]=T++;
    for (int i=0;i<2;++i)
    {
        cin>>n[i];
        for (int j=1;j<=n[i];++j)
        {
            cin>>b[i][j];
            string t;
            for (int k=0;k<b[i][j].size();++k)
            {
                t+=b[i][j][k];
                if (!m[t])
                    m[t]=T++;
                a[i][m[t]].push_back(j);
            }
            if (i==0)
                a[0][1].push_back(j);
        }
    }
}

int solve(string s,int st)
{
    int k=m[s];
    if (f[k]!=-1)
        return f[k];
    f[k]=(!st);
    for (auto i:a[st][k])
    {
        if (s.size()>=b[st][i].size())
            continue;
        string t=s+b[st][i][s.size()];
        int nst=solve(t,!st);
        if (nst==st)
        {
            f[k]=st;
            return f[k];
        }
    }
    return f[k];
}

void process()
{
    for (int i=1;i<T;++i)
        f[i]=-1;
    cout<<smp[solve("",0)];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    nhap();
    process();
    return 0;
}
