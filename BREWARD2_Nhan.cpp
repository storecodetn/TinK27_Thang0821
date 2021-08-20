#include <bits/stdc++.h>
using namespace std;
FILE *fi = freopen("BREWARD2.inp", "r", stdin);
FILE *fo = freopen("BREWARD2.out", "w", stdout);
const int maxn = 1e5+10;
int n, a[maxn];
int64_t f[maxn][5];

int64_t solve(int i, int cnt)
{
  if(i > n) return 0;
  if(f[i][cnt] != -1) return f[i][cnt];
  int64_t &x = f[i][cnt];
    x = max(x, solve(i+1, 0));
  if(cnt + 1 <= 2)
    x = max(x, solve(i+1, cnt + 1) + a[i]);
  x = max(x, solve(i+2, 1) + a[i+1]);
  return x;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin>>n;
  for (int i=1; i<=n; i++) cin>>a[i]; 
  memset(f, -1, sizeof f);
  cout<<solve(1, 0);
  return 0;
}