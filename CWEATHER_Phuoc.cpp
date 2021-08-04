#include <bits/stdc++.h>
using namespace std;
const int maxNode = 110, maxEdge = 5100;
struct edge
{
    int u, v, id;
    bool isBridge,used;
    edge(int _u = 0, int _v = 0,int _id = 0)
    {
        u = _u, v = _v, id = _id;
        isBridge = 0;
        used = 0;
    }
};
int numNode, numEdge, cnt, res;
int low[maxNode], num[maxNode], dep[maxNode], trace[maxNode];
edge e[maxEdge];
vector <int> g[maxNode];
void dfs(int u, int p)
{
    int v;
    num[u] = low[u] = ++cnt;
    dep[u] = dep[p] + 1;
    for(int id : g[u])
        if(!e[id].used)
        {
            e[id].used = 1;
            v = e[id].u ^ e[id].v ^ u;
            if(!num[v])
            {
                trace[v] = e[id].id;
                dfs(v,u);
                low[u] = min(low[u], low[v]);
                e[id].isBridge = low[v] > num[u];
            } else low[u] = min(low[u], num[v]);
        }
}
void process(int u, int v)
{
    if(dep[v] < dep[u]) swap(u, v);
    while(dep[v] > dep[u])
    {
        res += e[trace[v]].isBridge;
        v = e[trace[v]].u ^ e[trace[v]].v ^ v;
    }
    while(u != v)
    {
        res += e[trace[v]].isBridge;
        v = e[trace[v]].u ^ e[trace[v]].v ^ v;
        res += e[trace[u]].isBridge;
        u = e[trace[u]].u ^ e[trace[u]].v ^ u;
    }
}
int main()
{
    freopen("CWEATHER.inp","r",stdin);
    freopen("CWEATHER.out","w",stdout);
    int u,v;
    cin >> numNode >> numEdge;
    for(int i = 1; i <= numEdge; i++)
    {
        cin >> u >> v;
        e[i] = edge(u, v, i);
        g[u].push_back(i);
        g[v].push_back(i);
    }
    dfs(1,0);
    for(int i = 1; i <= numNode; i++)
        for(int j = i + 1 ; j <= numNode;j++)
            process(i,j);
    cout << res;
}
