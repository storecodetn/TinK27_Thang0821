#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("BREVERSE.inp", "r", stdin);
FILE *fo = freopen("BREVERSE.out", "w", stdout);
const int nxm = 2e5 + 10;
int a[nxm];
pair<int, int> b[nxm];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int m, n;
    cin >> s >> m;
    n = s.size();
    s = "." + s;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    sort(a + 1, a + m + 1);
    int sl = 1;
    b[sl].first = 1, b[sl].second = a[1];
    for(int i = 1; i < m; i++)
        if(a[i] == a[i + 1])
            b[sl].first++;
        else
        {
            b[sl].first %= 2;
            sl++;
            b[sl].first = 1;
            b[sl].second = a[i + 1];
        }
    b[sl].first %= 2;
    int sum = 0;
    for(int i = 1; i < sl; i++)
    {
        sum += b[i].first;
        if(sum % 2 == 1)
        {
            for(int j = b[i].second; j < b[i + 1].second; j++)
                swap(s[j], s[n - j + 1]);

        }
    }
    sum += b[sl].first;
    if(sum % 2 == 1)
    {
        int i = b[sl].second, j = n - b[sl].second + 1;
        while(i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << s[i];
    return 0;
}
/*
abcdefgh
3
1 2 3
hbfedcga
*/
