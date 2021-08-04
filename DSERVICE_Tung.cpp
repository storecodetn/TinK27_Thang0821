#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define pb push_back
#define ii pair<long long,long long>
long long d[N],n,s,ans;
vector<ii> a[N];
bool f[N],vi[N];
void dfs(int u)
{
    f[u]=true;
    for(auto x:a[u])
    {
        int v=x.first;
        long long w=x.second;
        if(!f[v])
        {
            dfs(v);
            d[u]=max(d[u],d[v]+w);
        }
    }
}
void xuly(int u,int p,long long cost)
{
    vi[u]=true;
    for(auto x:a[u])
    {
        int v=x.first;
        long long w=x.second;
        if(!vi[v])
        {
                long long Max=0;
                for(auto z:a[u])
                    if(z.first!=v)
                        Max=max(Max,d[z.first]+z.second);
                if(w<=s)
                    ans=min(ans,max(Max,d[v]));
                d[v]=max(d[v],w+Max);
                d[u]=Max;
                ans=min(ans,d[v]);
                xuly(v,u,w);
        }
    }
    if(p!=-1)
    {
                long long Max=0;
                for(auto z:a[u])
                    if(z.first!=p)
                        Max=max(Max,d[z.first]+z.second);
                d[p]=max(d[p],cost+Max);
                d[u]=Max;
    }
}
int main()
{
    freopen("DSERVICE.INP","r",stdin);
    freopen("DSERVICE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    ans=1e18;
    for(int i=1;i<n;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        a[u].pb({v,w});
        a[v].pb({u,w});
    }
    dfs(1);
    ans=min(ans,d[1]);
    xuly(1,-1,0);
    cout<<ans;
}
