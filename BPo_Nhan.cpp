#include <bits/stdc++.h>
using namespace std;
FILE *fi = freopen("BPo.inp", "r", stdin);
FILE *fo = freopen("BPo.out", "w", stdout);
int n;
vector<int> a;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  int ans = 0;
  for (int i=1; i<=n; i++)
  {
    int x;
    cin>>x;
    while(a.size() && a.back() > x)
      a.pop_back();
    if(a.size() && a.back() == x)
      continue;
    if(x!=0)
    {
      ans++;
      a.push_back(x);
    }
  }
  cout<<ans;
  return 0; 
}