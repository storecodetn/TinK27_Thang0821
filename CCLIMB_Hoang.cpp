#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("CCLIMB.inp", "r", stdin);
FILE *fo = freopen("CCLIMB.out", "w", stdout);
int ans, n, m;
vector <vector <int> > a;
vector <vector <int> > dp;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int dfs(int x, int y)
{
    if(dp[x][y] != 0)
        return dp[x][y];
    dp[x][y] = 1;
    int res = 0;
    for(int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(check(X, Y) && a[X][Y] > a[x][y])
            res = max(res, dfs(X, Y));
    }
    dp[x][y] += res;
    return dp[x][y];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n + 10), dp.resize(n + 10);
    for(int i = 1; i <= n; i++)
        a[i].resize(m + 10), dp[i].resize(m + 10);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(!dp[i][j])
                dfs(i, j);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            ans = max(ans, dp[i][j]);
    cout << ans;
    return 0;
}
/*
2 3
1 1 1
1 1 1
*/
