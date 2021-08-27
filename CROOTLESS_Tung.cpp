#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q,cha[N],p[N][30],Max[N];
int level[N];
int f[N];
vector<int> a[N];
void dfs(int u,int k)
{
    level[u]=k;
    Max[u]=level[u];
    for(auto v:a[u])
        if(level[v]==0)
            {
                dfs(v,k+1);
                cha[v]=u;
                Max[u]=max(Max[u],Max[v]);
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
int main()
{
    freopen("CROOTLESS.inp","r",stdin);
    freopen("CROOTLESS.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,1);
    cha[1]=-1;
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
        int x,y,z;
        cin>>x>>y>>z;
        int xy=lca(x,y);
        int xz=lca(x,z);
        int yz=lca(y,z);
        if(yz==xz)
            {
                cout<<xy<<"\n";
                continue;
            }
        if(xz!=yz)
            if(level[xz]>level[yz])
                cout<<xz<<"\n";
            else
                cout<<yz<<"\n";

    }
}
