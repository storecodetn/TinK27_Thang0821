#include <bits/stdc++.h>
using namespace std;
#define Max 100000000
int n,m,number[200001],low[200001],cha[200001],dem,ans,be[1000],en[1000];
vector<int> a[200001];
bool vi[200001],ok,f[1000];
void xuly(int u)
{
    dem++;
    f[u]=true;
    be[u]=dem;
    for(auto v:a[u])
        if(!f[v])
            xuly(v);
    en[u]=dem;
}
void dfs(int u)
{
    vi[u]=true;
    dem++;
    number[u]=dem;
    low[u]=Max;
    for(auto v:a[u])
    {
        if(!vi[v])
        {
            cha[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=number[v])
                {
                    int x,y;
                    if(be[u]>be[v])
                        x=v;
                    else
                        x=u;
                    y=u+v-x;
                    ans+=(n-en[v]+be[v]-1)*(en[v]-be[v]+1);
                }
        }
        else
        if(cha[u]!=v)
            low[u]=min(low[u],number[v]);
    }

}
int main()
{
    freopen("CWEATHER.INP","r",stdin);
    freopen("CWEATHER.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    xuly(1);
    dem=0;
    dfs(1);
    cout<<ans;
}
