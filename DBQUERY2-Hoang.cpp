#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("DBQUERY2.inp", "r", stdin);
FILE *fo = freopen("DBQUERY2.out", "w", stdout);
const int nxm = 2e3 + 10;
char a[nxm][nxm];
int n, m, q, f[nxm][nxm], fh[nxm][nxm], fd[nxm][nxm];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j], a[i][j] -= '0';
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1] + a[i][j] - f[i - 1][j - 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            fh[i][j] = fh[i - 1][j] + fh[i][j - 1] - fh[i - 1][j - 1] + (a[i][j] == a[i][j - 1] && a[i][j] == 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            fd[i][j] = fd[i - 1][j] + fd[i][j - 1] - fd[i - 1][j - 1] + (a[i][j] == a[i - 1][j] && a[i][j] == 1);
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int v = f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
        int e = fh[x2][y2] - fh[x1 - 1][y2] - fh[x2][y1] + fh[x1 - 1][y1];
        e += fd[x2][y2] - fd[x1][y2] - fd[x2][y1 - 1] + fd[x1][y1 - 1];
        cout << v - e << "\n";
    }
    return 0;
}
