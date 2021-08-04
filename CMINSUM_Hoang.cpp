#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("CMINSUM.inp", "r", stdin);
FILE *fo = freopen("CMINSUM.out", "w", stdout);
const int nxm = 1e5 + 10;
int n, s[nxm];
int sum(long long x)
{
    int res = 0;
    while(x > 0)
    {
        res += x%10;
        x /= 10;
    }
    return res;
}
void bfs()
{
    queue <int> q;
    for(int i = 0; i <= n - 1; i++)
        s[i] = 1e9;
    for(int i = 1; i <= 9; i++)
    {
        s[i%n] = min(s[i%n], i);
        q.push(i%n);
    }
    while(q.size())
    {
        long long u = q.front();
        q.pop();
        for(int i = 0; i <= 9; i++)
        {
            if(s[u] + i < s[(u*10 + i)%n])
            {
                s[(u*10 + i)%n] = s[u] + i;
                q.push((u*10 + i)%n);
            }
        }
    }
}
int main()
{
    cin >> n;
    bfs();
    cout << s[0];
    return 0;
}
