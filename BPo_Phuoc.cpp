#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;
int n;
int a[maxN];
int r[maxN];
int sumPrefix[maxN];
deque <int> dq;

int main()
{
    freopen("BPo.inp", "r", stdin);
    freopen("BPo.out", "w", stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int minVal = 2e9, cnt = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i; i--)
    {
        minVal = min(minVal, a[i]);
        while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
        if (dq.empty()) r[i] = n + 1;
        else r[i] = dq.back();
        dq.push_back(i);
    }
    if(minVal)
    {
        cnt++;
        for (int i = 1; i <= n; i++) a[i] -= minVal;
    }
    for (int i = 1; i <= n; i++)
    {
        sum += sumPrefix[i];
        if(sum == a[i]) continue;
        cnt++;
        sumPrefix[r[i]] -= a[i] - sum;
        sum += (a[i] - sum);
    }
    cout << cnt;
}
