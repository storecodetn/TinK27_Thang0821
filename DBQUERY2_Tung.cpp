#include <bits/stdc++.h>
using namespace std;
int n,m,q,a[2001][2001],b[2001][2001],c[2001][2001],d[2001][2001];
int main()
{
    freopen("DBQUERY2.INP","r",stdin);
    freopen("DBQUERY2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        char x;
        cin>>x;
        a[i][j]=x-'0';
        b[i][j]=b[i][j-1]+b[i-1][j]-b[i-1][j-1]+a[i][j];
        c[i][j]=c[i][j-1]+c[i-1][j]-c[i-1][j-1];
        d[i][j]=d[i][j-1]+d[i-1][j]-d[i-1][j-1];
        if(a[i][j]==1 && a[i][j]==a[i-1][j])
            c[i][j]++;
        if(a[i][j]==1 && a[i][j]==a[i][j-1])
            d[i][j]++;
    }
    for(int i=1;i<=q;i++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int e=b[x2][y2]-b[x1-1][y2]-b[x2][y1-1]+b[x1-1][y1-1];
        int v=c[x2][y2]-c[x1][y2]-c[x2][y1-1]+c[x1][y1-1];
        v+=d[x2][y2]-d[x1-1][y2]-d[x2][y1]+d[x1-1][y1];
        cout<<e-v<<"\n";
    }
}
