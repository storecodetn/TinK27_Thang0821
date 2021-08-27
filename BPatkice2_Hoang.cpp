#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("BPatkice2.inp", "r", stdin);
FILE *fo = freopen("BPatkice2.out", "w", stdout);
vector <vector <char> > a;
vector <vector <int> > d;
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char x[4] = {'^', '>', 'v', '<'};
bool check(pair<int, int> x)
{
    return x.first >= 1 && x.first <= n && x.second >= 1 && x.second <= m;
}
void bfs(pair<int, int> s)
{
    deque <pair<int, int> >q;
    q.push_front(s);
    d[s.first][s.second] = -1;
    while(q.size())
    {
        pair<int, int> u, v;
        u = q.front();
        q.pop_front();
        for(int i = 0; i < 4; i++)
        {
            v.first = u.first + dx[i];
            v.second = u.second + dy[i];
            if(check(v) && d[v.first][v.second] > d[u.first][u.second] + (a[u.first][u.second] != x[i]))
            {
                d[v.first][v.second] = d[u.first][u.second] + (a[u.first][u.second] != x[i]);
                if(a[u.first][u.second] != x[i])
                    q.push_back(v);
                else
                    q.push_front(v);

            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a = vector <vector <char> > (n + 10, vector <char> (m + 10));
    d = vector <vector <int> > (n + 10, vector <int> (m + 10));
    pair<int, int> s, t;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j], d[i][j] = 1e9;
            if(a[i][j] == 'o')
                s.first = i, s.second = j;
            if(a[i][j] == 'x')
                t.first = i, t.second = j;
        }
    bfs(s);
    cout << d[t.first][t.second];
    return 0;
}
