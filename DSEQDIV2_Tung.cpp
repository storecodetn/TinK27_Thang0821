#include <bits/stdc++.h>
using namespace std;
const int N=(1<<14)+10;
long long t,n,a[N],dp[N];
map<long long,int> ma[20];
int main()
{
    freopen("DSEQDIV2.INP","r",stdin);
    freopen("DSEQDIV2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ma[t][0]=0;
        for(int i=1;i<=n;i++)
            {
                long long x;
                cin>>x;
                a[i]=a[i-1]+x;
                ma[t][a[i]]=i;
                dp[i]=0;
            }
        long long p=a[n];
        if(p==0)
        {
            cout<<n-1<<"\n";
            continue;
        }
        while(p%2==0 && p!=0)
            p/=2;
        while(p<=a[n])
        {
            for(int i=n;i>=1;i--)
            {
                int pos=ma[t][a[i]-p];
                if(pos==0 && a[i]-p!=0)
                {
                    dp[i]=0;
                    continue;
                }
                long long p2=p/2;
                if(p%2==1)
                    {
                    dp[i]=0;
                    continue;
                }
                int pos2=ma[t][a[i]-p2];
                if(pos2==0 && a[i]-p2!=0)
                    {
                    dp[i]=0;
                    continue;
                }
                dp[i]=1+max(dp[pos2],dp[i]);
            }
            if(p==a[n])
                break;
            p=p*2;
        }
        cout<<dp[n]<<"\n";
    }
}
