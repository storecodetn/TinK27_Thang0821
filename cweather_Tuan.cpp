#include <bits/stdc++.h>
using namespace std;

const int nmax=1e2+1;
const int mmax=5e3+1;
int n,m,res,dem,low[nmax],number[nmax],t[nmax][10],d[nmax],trace[nmax];
bool f[nmax],cau[nmax][nmax];
vector<int> a[nmax],b[nmax];
//-----------
void dfs(int u,int p)
{
    d[u]=d[p]+1;
    t[u][0]=p;
    f[u]=true;
    number[u]=++dem;
    low[u]=nmax+1;
    for (int i=1;i<=7;i++)
        t[u][i]=t[t[u][i-1]][i-1];
    for (auto v:a[u])
        if (!f[v])
        {
            trace[v]=u;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]>=number[v])
            {
                cau[u][v]=cau[v][u]=1;
            }
        }
        else if (trace[u]!=v)
        {
            low[u]=min(low[u],number[v]);
        }
}
//-----------
int lca(int u,int v)
{
    if (d[u]<d[v])
        swap(u,v);
    int diff=d[u]-d[v];
    for (int i=0;i<=7;i++)
        if ((diff>>i)&1)
            u=t[u][i];
    if (u==v)
        return u;
    for (int i=7;i>=0;i--)
        if (t[u][i]!=t[v][i])
        {
            u=t[u][i];
            v=t[v][i];
        }
    return t[u][0];
}
//------------
int kq(int x,int y)
{
    int tam=0;
    int bruh=lca(x,y);
    while (x!=bruh)
    {
        tam+=cau[x][trace[x]];
        x=trace[x];
    }
    while (y!=bruh)
    {
        tam+=cau[y][trace[y]];
        y=trace[y];
    }
    return tam;
}
//------------
int main()
{
    freopen("cweather.inp","r",stdin);
    freopen("cweather.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            res+=kq(i,j);
        }
    cout<<res;
    return 0;
}
