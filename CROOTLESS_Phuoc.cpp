#include <bits/stdc++.h>
using namespace std;

const int maxNode = 1e5 + 100;
int numNode, numQuery, num;
int sta[maxNode], fin[maxNode], d[maxNode];
int pa[maxNode][19];
vector <int> g[maxNode];

void dfs(int u, int p)
{
    sta[u] = ++num;
    pa[u][0] = p;
    d[u] = d[p] + 1;
    for (int v : g[u])
        if (v != p) dfs(v, u);
    fin[u] = num;
}

bool inSubTree(int u, int v)
{
    return (sta[u] <= sta[v] && fin[v] <= fin[u]);
}

int lca(int u, int v)
{
    if (d[u] < d[v]) swap(u, v);
    for (int i = 17; i >= 0; i--)
        if (d[pa[u][i]] >= d[v]) u = pa[u][i];
    for (int i = 17; i >= 0; i--)
        if (pa[u][i] != pa[v][i]) u = pa[u][i], v = pa[v][i];
    while (u != v)
    {
        u = pa[u][0];
        v = pa[v][0];
    }
    return u;
}

int fakeLca(int u, int v, int root)
{
    if (inSubTree(root, u) || inSubTree(root, v)) return root;
    for (int i = 17; i >= 0; i--)
        if (pa[root][i] > 0 && !inSubTree(pa[root][i], u) && !inSubTree(pa[root][i], v)) root = pa[root][i];
    while(!inSubTree(pa[root][0], u) && !inSubTree(pa[root][0], v))
        root = pa[root][0];
    return pa[root][0];
}

int main()
{
    freopen("CROOTLESS.inp", "r", stdin);
    freopen("CROOTLESS.out", "w", stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int u, v, r, anc;
    cin >> numNode;
    for (int i = 1; i < numNode; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int j = 1; j <= 17; j++)
        for (int i = 1; i <= numNode; i++)
            pa[i][j] = pa[pa[i][j - 1]][j - 1];
    cin >> numQuery;
    while (numQuery--)
    {
        cin >> u >> v >> r;
        anc = lca(u, v);
        if(anc == r || !inSubTree(anc, r))
        {
            cout << anc << "\n";
            continue;
        }
        cout << fakeLca(u, v, r) << "\n";
    }
}
