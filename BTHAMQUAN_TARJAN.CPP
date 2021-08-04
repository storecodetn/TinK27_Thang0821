#include<bits/stdc++.h>
using namespace std;
FILE *fi=freopen("BTHAMQUAN.inp","r",stdin);
FILE *fo=freopen("BTHAMQUAN.OUT","w",stdout);

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back


const ll oo = 1e15+7 ;
const ll mod = 1e9+7 ;
const int N = 2e5+7 ;

int m, n, cnt = 0, bridge = 0 ;
int low[N], num[N] ;
vector<int> g[N] ;

void Tarjan(int u,int p)
{
    num[u] = low[u] = ++cnt ;
    for(auto v : g[u])
    {
        if(v != p)
        {
            if(num[v]) low[u] = min(low[u] , num[v]) ;
            else
            {
                Tarjan(v,u) ;
                low[u] = min(low[u] , low[v]) ;
                if(low[v] >= num[v])
                    bridge++ ;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    cin >> n>>m ;
    int u, v ;
    For(i,1,n-1)
    {
        cin >> u >> v ;
        g[u].pb(v) ;
        g[v].pb(u) ;
    }
    n++ ;
    For(i,1,m)
    {
        cin >> u >> v ;
        g[u].pb(n) ;
        g[n].pb(u) ;
        g[v].pb(n) ;
        g[n].pb(v) ;
    }
    For(i,1,n)
        if(!num[i])
    		Tarjan(i,i) ;
    cout << bridge ;
    return 0;
}