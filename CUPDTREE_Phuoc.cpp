#include <bits/stdc++.h>
using namespace std;
const int maxNode = 1e5 + 100;
int numNode,numQuery;
int dep[maxNode];
long long sum[maxNode], val[maxNode];
int pa[maxNode][18];
queue <int> q;
vector <int> g[maxNode];
void dfs(int u,int p)
{
    pa[u][0] = p;
    dep[u] = dep[p] + 1;
    for(int v : g[u])
        if(v != p) dfs(v,u);
}
void process(int u, int v, int w)
{
    sum[u] += w; sum[v] += w;
    if(dep[v] < dep[u]) swap(u,v);
    for(int i = 16; i >= 0; i--)
        if(dep[pa[v][i]] >= dep[u]) v = pa[v][i];
    for(int i = 16; i >= 0; i--)
        if(pa[v][i] != pa[u][i])
            v = pa[v][i], u = pa[u][i];
    while(u != v) u = pa[u][0], v = pa[v][0];
    sum[u] -= 2*w;
    val[u] += w;
}
void dfsGetVal(int u, int p)
{
    for(int v : g[u])
        if(v != p)
        {
            dfsGetVal(v, u);
            sum[u] += sum[v];
        }
}
int main()
{
    freopen("CUPDTREE.inp","r",stdin);
    freopen("CUPDTREE.out","w",stdout);
    int u, v, w;
    cin >> numNode;
    for(int i = 1; i <= numNode; i++)
        cin >> val[i];
    for(int i = 1; i < numNode; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int j = 1; j <= 16; j++)
        for(int i = 1; i <=numNode; i++)
            pa[i][j] = pa[pa[i][j-1]][j-1];
    cin >> numQuery;
    while(numQuery--)
    {
        cin >> u >> v >> w;
        process(u, v, w);
    }
    dfsGetVal(1,0);
    for(int i = 1; i <= numNode; i++)
        cout << val[i] + sum[i] << " ";
}
