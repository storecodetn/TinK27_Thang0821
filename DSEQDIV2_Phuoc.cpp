#include <bits/stdc++.h>
using namespace std;

const int maxN = (1<<14) + 5;
int n;
int a[maxN];
long long sum[maxN];

long long getS(int l, int id)
{
    return sum[id] - sum[l - 1];
}
int divAndConq(int l, int r)
{
    if(l == r) return 0;
    int low = l, high = r, mid, nextPos = 0;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        if(getS(l, mid) * 2 <= getS(l, r))
        {
            low = mid + 1;
            nextPos = max(nextPos, mid);
        }
        else high = mid - 1;
    }
    if(getS(l, nextPos) * 2 == getS(l, r))
        return 1 + max(divAndConq(l, nextPos), divAndConq(nextPos + 1, r));
    return 0;
}
int main()
{
    freopen("DSEQDIV2.inp", "r", stdin);
    freopen("DSEQDIV2.out", "w", stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    bool trap;
    cin >> t;
    while(t--)
    {
        trap = false;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
            if(a[i] != 0) trap = true;
        }
        if(trap) cout << divAndConq(1,n) << "\n";
        else cout << n - 1 << "\n";
    }
}
