#include <bits/stdc++.h>

using namespace std;

FILE *fi=freopen("Cpapricice.inp","r",stdin);
FILE *fo=freopen("Cpapricice.out","w",stdout);

const int N=200001;

int n,d[N],kq=INT_MAX;
vector<int> a[N];
set<int> q[2];

void nhap()
{
    cin>>n;
    for (int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs1(int u,int pa)
{
    d[u]=1;
    for (auto v:a[u])
    {
        if (v==pa)
            continue;
        dfs1(v,u);
        d[u]+=d[v];
    }
}

void dfs2(int u,int pa)
{
    q[0].insert(d[u]);

    int k=n,x=0;
    auto j=q[0].lower_bound((n+d[u])/2);
    if (j!=q[0].end())
    {
        k=min(k,abs((*j)-(n+d[u])/2));
        x=(*j);
    }
    if (j!=q[0].begin())
    {
        j--;
        if (k>abs((*j)-(n+d[u])/2))
            x=(*j);
    }
    kq=min(kq,max({d[u],x-d[u],n-x})-min({d[u],x-d[u],n-x}));

    k=n;x=0;
    j=q[1].lower_bound((n-d[u])/2);
    if (j!=q[1].end())
    {
        k=min(k,abs((*j)-(n-d[u])/2));
        x=(*j);
    }
    if (j!=q[1].begin())
    {
        j--;
        if (k>abs((*j)-(n-d[u])/2))
            x=(*j);
    }
    kq=min(kq,max({d[u],x,n-x-d[u]})-min({d[u],x,n-x-d[u]}));

    for (auto v:a[u])
    {
        if (v==pa)
            continue;
        dfs2(v,u);
    }

    q[0].erase(q[0].lower_bound(d[u]));
    q[1].insert(d[u]);
}

void process()
{
    dfs1(1,0);
    dfs2(1,0);
    cout<<kq;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    nhap();
    process();
    return 0;
}
