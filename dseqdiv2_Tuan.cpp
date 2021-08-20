#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for (int i=a;i<=b;i++)
typedef pair<int,int> ii;

const int nmax=16385;
int q,n,a[nmax];
long long s[nmax];
//-------------
int tri_de_chia(int i,int j)
{
    if (i==j)
        return 0;
    int mid=(i+j)/2;
    int l=i,r=j,res=-1;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (s[mid]-s[i-1]<=(s[j]-s[mid]))
        {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    if (s[res]-s[i-1]==s[j]-s[res])
    {
        return max(tri_de_chia(i,res),tri_de_chia(res+1,j))+1;
    }
    return 0;
}
//-------------
int main()
{
    freopen("DSEQDIV2.INP","r",stdin);
    freopen("DSEQDIV2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>q;
    while (q--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            {
                cin>>a[i];
                s[i]=s[i-1]+a[i];
            }
        if (s[n]==0)
        {
            cout<<n-1<<"\n";
            continue;
        }
        cout<<tri_de_chia(1,n)<<"\n";
    }
    return 0;
}
