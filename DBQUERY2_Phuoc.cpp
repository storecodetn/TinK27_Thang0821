#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e3 + 10;
int numRow, numCol;
int sumNode[maxN][maxN], a[maxN][maxN];
int sumRow[maxN][maxN], sumCol[maxN][maxN];

int getSumNode(int u, int v, int p, int q)
{
    return sumNode[p][q] - sumNode[u - 1][q] -
            sumNode[p][v - 1] + sumNode[u - 1][v - 1];
}

int getSumRow(int u, int v, int p, int q)
{
    return sumRow[p][q] - sumRow[u][q] -
            sumRow[p][v - 1] + sumRow[u][v - 1];
}

int getSumCol(int u, int v, int p, int q)
{
    return sumCol[p][q] - sumCol[p][v] - sumCol[u - 1][q]
            + sumCol[u - 1][v];
}
int main()
{
    freopen("DBQUERY2.inp", "r", stdin);
    freopen("DBQUERY2.out", "w", stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    char c;
    int query;
    cin >> numRow >> numCol >> query;
    for(int i = 1; i <= numRow; i++)
        for(int j = 1; j <= numCol; j++)
        {
            cin >> c;
            a[i][j] = c - '0';
        }
    for(int i = 1; i <= numRow; i++)
        for(int j = 1; j <= numCol; j++)
        {
            sumNode[i][j] = sumNode[i - 1][j] + sumNode[i][j - 1] -
                            sumNode[i - 1][j - 1] + a[i][j];
            sumCol[i][j] = sumCol[i - 1][j] + sumCol[i][j - 1] -
                            sumCol[i - 1][j - 1];
            sumRow[i][j] = sumRow[i-1][j] + sumRow[i][j - 1] -
                            sumRow[i - 1][j - 1];
            if(a[i][j] == 1 && a[i][j -1 ] == 1) sumCol[i][j]++;
            if(a[i][j] == 1 && a[i - 1][j] == 1) sumRow[i][j]++;
        }
    int u, v, p, q, nodes, adjRow, adjCol;
    while(query--)
    {
        cin >> u >> v >> p >> q;
        nodes = getSumNode(u, v, p, q);
        adjRow = getSumRow(u, v, p, q);
        adjCol = getSumCol(u, v, p, q);
        cout << nodes - adjRow - adjCol << "\n";
    }
}
