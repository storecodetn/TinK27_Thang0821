#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,q,cha[N],p[N][30],d[N],vao[N],t,ra[N],chan[N];
long long level[N];
vector<int> a[N];
bool f[N];
void dfs(int u,int k)
{
    level[u]=k;
    for(auto v:a[u])
        if(level[v]==0)
            {
                dfs(v,k+1);
                cha[v]=u;
            }
}
int lca(int x,int y)
{
    if(level[y]>level[x])
        swap(x,y);
    for(int i=20;i>=0;i--)
        if((level[x]-(1<<i))>=level[y])
            x=p[x][i];
    if(x==y)
        return x;
    for(int i=20;i>=0;i--)
        if(p[x][i]!=p[y][i] && p[x][i]!=-1)
    {
        x=p[x][i];
        y=p[y][i];
    }
    return cha[x];
}
void xuly(int u)
{
    f[u]=true;
    chan[u]=vao[u];
    for(auto v:a[u])
        if(!f[v])
    {
        xuly(v);
        chan[u]+=chan[v];
    }
    d[u]+=chan[u];
    chan[u]+=ra[u];
}
int main()
{
    freopen("CUPDTREE.inp","r",stdin);
    freopen("CUPDTREE.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(a[i].size()==1)
    {
        dfs(i,1);
        cha[i]=-1;
        t=i;
        break;
    }
    for(int i=0;i<=20;i++)
        for(int j=1;j<=n;j++)
            p[j][i]=-1;
    for(int i=1;i<=n;i++)
        p[i][0]=cha[i];
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            if(p[j][i-1]!=-1)
                p[j][i]=p[p[j][i-1]][i-1];
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        int x=lca(u,v);
        vao[u]+=w;
        vao[v]+=w;
        ra[x]-=w*2;
        d[x]-=w;
    }
    xuly(t);
    for(int i=1;i<=n;i++)
        cout<<d[i]<<" ";
}
