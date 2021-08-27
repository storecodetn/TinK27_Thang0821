#include <bits/stdc++.h>
using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};
struct node
{
    int row, col, dis;
};
int numRow, numCol;
deque <node> dq;

bool inTable(int u, int v)
{
    return 1 <= u && u <= numRow && 1 <= v && v <= numCol;
}

pair <int, int> enCode(char c)
{
    if(c == '<') return {0, -1};
    if(c == '>') return {0, 1};
    if(c == '^') return {-1, 0};
    if(c == 'v') return {1, 0};
    else return {0, 0};
}

int main()
{
    freopen("BPatkice2.inp", "r", stdin);
    freopen("BPatkice2.out", "w", stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int sRow, sCol, eRow, eCol, u, v, p, q, now;
    pair <int, int> dir;
    cin >> numRow >> numCol;
    char a[numRow + 3][numCol + 3];
    int d[numRow + 3][numCol + 3];
    for (int i = 1; i <= numRow; i++)
        for (int j = 1; j <= numCol; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'o') sRow = i, sCol = j;
            if (a[i][j] == 'x') eRow = i, eCol = j;
            d[i][j] = -1;
        }
    d[sRow][sCol] = 0;
    for (int i = 0; i < 4; i++)
    {
        p = sRow + dr[i];
        q = sCol + dc[i];
        if(inTable(p, q))
        {
            d[p][q] = d[sRow][sCol];
            dq.push_back({p, q, d[p][q]});
        }
    }
    while (dq.size())
    {
        u = dq.front().row;
        v = dq.front().col;
        now = dq.front().dis;
        dq.pop_front();
        if(now != d[u][v]) continue;
        dir = enCode(a[u][v]);
        for (int i = 0; i < 4; i++)
        {
            p = u + dr[i];
            q = v + dc[i];
            if(!inTable(p, q)) continue;
            if(dir.first == dr[i] && dir.second == dc[i] && (d[p][q] > d[u][v] || d[p][q] == -1))
            {
                d[p][q] = d[u][v];
                dq.push_front({p, q, d[p][q]});
            }
            if((dir.first != dr[i] || dir.second != dc[i]) && (d[p][q] > d[u][v] + 1 || d[p][q] == -1))
            {
                d[p][q] = d[u][v] + 1;
                dq.push_back({p, q, d[p][q]});
            }
        }
    }
    cout << d[eRow][eCol];
}
