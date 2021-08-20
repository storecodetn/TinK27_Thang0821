#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for (int i=a;i<=b;i++)
typedef pair<int,int> ii;

const int nmax=2e3+1;
int n,m,q,a[nmax][nmax],f[nmax][nmax],fh[nmax][nmax],fd[nmax][nmax];
//----------------
int main()
{
    freopen("dbquery2.inp","r",stdin);
    freopen("dbquery2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            {
                char x;
                cin>>x;
                a[i][j]+=(x=='1');
            }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
            fh[i][j]=fh[i-1][j]+fh[i][j-1]-fh[i-1][j-1]+(a[i][j]==a[i][j-1] && a[i][j]==1);
            fd[i][j]=fd[i-1][j]+fd[i][j-1]-fd[i-1][j-1]+(a[i][j]==a[i-1][j] && a[i][j]==1);
        }
    while (q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int v=f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1];
        int e=fh[x2][y2]-fh[x1-1][y2]-fh[x2][y1]+fh[x1-1][y1];
        int e2=fd[x2][y2]-fd[x1][y2]-fd[x2][y1-1]+fd[x1][y1-1];
        cout<<v-e-e2<<"\n";
    }
    return 0;
}
