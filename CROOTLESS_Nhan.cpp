#include <bits/stdc++.h>
using namespace std;
FILE *fi = freopen("CROOTLESS.inp", "r", stdin);
FILE *fo = freopen("CROOTLESS.out", "w", stdout);
const int maxn = 1e5+10;
int n, q, r;
vector<int> g[maxn];  
int depth[maxn], T[maxn][33], parent[maxn];

void dfs(int u, int p)
{
  depth[u] = depth[p] + 1;
  T[u][0] = p;
  for (int i=1; i<17; i++)
    T[u][i] = T[T[u][i-1]][i-1];
  for (auto v:g[u])
  {
    if(v == p)
      continue;
    dfs(v, u);
  }
}

int lca(int u, int v)
{
  if(depth[u] < depth[v])
    swap(u, v);
  int diff = depth[u] - depth[v];
  for (int i = 0; i<17; i++)
    if((diff>>i)&1)
      u = T[u][i];
  if(u == v) return u;
  for(int i=16; i>=0; i--)
  {
    if(T[u][i] != T[v][i])
    {
      u = T[u][i];
      v = T[v][i];
    }
  }
  return T[u][0];
}

int Depth(int u)
{
  return depth[u] + depth[r] - 2*depth[lca(u, r)];
}

int updatelca(int u, int v)
{
  int depthu = Depth(u);
  int depthv = Depth(v);
  if(Depth(u) < Depth(v))
    swap(u, v);
    if(Depth(u) > Depth(v))
    {
      bool f = 0;
      while(f == 0)
      {
        for (auto z:g[u])
        {
          if(Depth(z) == Depth(u) - 1)
          {
            u = z;
            if(Depth(z) == Depth(v))
            {
              f = 1;
              break;
            }
          }
        }
      }
    }
    if(u == v) return u;
    if(Depth(u) == Depth(v))
    {
      while(u != v)
      {
        for (auto z:g[u])
        {
          if(Depth(z) == Depth(u) - 1)
          {
            u = z;
            break;
          }
        }
        for (auto z:g[v])
        {
          if(Depth(z) == Depth(v) - 1)
          {
            v = z;
            break;
          }
        }
      }
    }
  return u;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin>>n;
  for (int i=1; i<n; i++)
  {
    int u, v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cin>>q;
  dfs(1, 0);
  while(q--)
  {
    int u, v;
    cin>>r>>u>>v;
    if(r == 1) cout<<lca(u,v)<<"\n";
    else
      cout<<updatelca(u, v)<<"\n";
  }
  return 0;
}