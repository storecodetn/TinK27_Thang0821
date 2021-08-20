#include <bits/stdc++.h>
using namespace std;
FILE *fi = freopen("BREVERSE.inp", "r", stdin);
FILE *fo = freopen("BREVERSE.OUT", "w", stdout);
const int N = 2e5+10;
string s;
int m;
int d[N];

int main()
{
  ios_base::sync_with_stdio(false);
  cin>>s;
  cin>>m;
  int S = s.size();
  for (int i=1; i<=m; i++)
  {
    int x;
    cin>>x;
    d[x] ++;
    d[S-x+2] --;
  }
  for (int i=1; i<=S; i++)
    d[i] += d[i-1];
  int l = 1, r = S;
  while(l < r)
  {
    if(d[l]%2)
    {
      swap(s[l-1], s[r-1]);
    }
    l ++;
    r --;
  }
  cout<<s;
  return 0;
}