#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("BREWARD2.inp", "r", stdin);
FILE *fo = freopen("BREWARD2.out", "w", stdout);
const int nxm = 1e5 + 10;
long long dp[nxm];
int a[nxm], n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dp[1] = a[1], dp[2] = a[1] + a[2], dp[3] = max({dp[2], 1ll*a[1] + a[3], 1ll*a[2] + a[3]});
    for(int i = 4; i <= n; i++)
        dp[i] = max({dp[i - 1], dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]});
    cout << dp[n];
    return 0;
}
/*
5
10 10 1 1 1 1 10
*/
