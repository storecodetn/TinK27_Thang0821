#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for (int i=a;i<=b;i++)
typedef pair<int,int> ii;

const int nmax=1e5+1;
long long n,m,par[nmax],t[nmax][18],d[nmax],b[nmax];
vector<int> a[nmax];
//-----------
void dfs(int u,int p)
{
    d[u]=d[p]+1;
    t[u][0]=p;
    par[u]=p;
    for (int i=1;i<=17;i++)
        t[u][i]=t[t[u][i-1]][i-1];
    for (auto v:a[u])
    {
        if (v!=p)
            dfs(v,u);
    }
}
//------------
int lca(int u,int v)
{
    if (d[u]<d[v])
        swap(u,v);
    int diff=d[u]-d[v];
    for (int i=0;i<=17;i++)
        if ((diff>>i)&1)
            u=t[u][i];
    if (u==v)
        return u;
    for (int i=17;i>=0;i--)
        if (t[u][i]!=t[v][i])
        {
            u=t[u][i];
            v=t[v][i];
        }
    return t[u][0];
}
//------------
void update(int x,int y,int val)
{
    int bruh=lca(x,y);
    while (x!=bruh)
    {
        b[x]+=val;
        x=par[x];
    }
    while (y!=bruh)
    {
        b[y]+=val;
        y=par[y];
    }
    b[bruh]+=val;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cupdtree.inp","r",stdin);
    freopen("cupdtree.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>b[i];
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    cin>>m;
    while (m--)
    {
        int u,v,val;
        cin>>u>>v>>val;
        update(u,v,val);
    }
    for (int i=1;i<=n;i++)
        cout<<b[i]<<" ";
    return 0;
}
