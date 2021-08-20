#include <bits/stdc++.h>
using namespace std;

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};
int numRow, numCol, ans;
vector <vector<int>> a, f;

int dp(int u, int v)
{
    if(u == 1 && v == 3)
    {
        int cnt = 1;
    }
    int &res = f[u][v];
    if(res != 0) return res;
    res = 1;
    int p, q;
    for(int i = 0; i < 4; i++)
    {
        p = u + dr[i];
        q = v + dc[i];
        if(p >= 1 && p <= numRow && q >= 1 && q <= numCol && a[u][v] < a[p][q])
            res = max(res, 1 + dp(p, q));
    }
    return res;
}
int main()
{
    freopen("CCLIMB.inp", "r", stdin);
    freopen("CCLIMB.out", "w", stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> numRow >> numCol;
    a.resize(numRow + 5);
    for(int i = 1; i <= numRow; i++) a[i].resize(numCol + 5);
    f.resize(numRow + 5);
    for(int i = 1; i <= numRow; i++) f[i].resize(numCol + 5);

    for(int i = 1; i <= numRow; i++)
        for(int j = 1; j <= numCol; j++) cin >> a[i][j];

    for(int i = 1; i <= numRow; i++)
        for(int j = 1; j <= numCol; j++) ans = max(ans, dp(i, j));

    cout << ans;
}
