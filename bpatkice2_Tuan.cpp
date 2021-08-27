#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for (int i=a;i<=b;i++)
typedef pair<int,int> ii;

const int nmax=2e3+1;
int n,m,s1,s2,e1,e2;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char b[]={'v','^','>','<'};
//--------------
int main()
{
    freopen("bpatkice2.inp","r",stdin);
    freopen("bpatkice2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    char a[n+1][m+1];
    int d[n+1][m+1];
    for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                if (a[i][j]=='o')
                {
                    s1=i;
                    s2=j;
                }
                if (a[i][j]=='x')
                {
                    e1=i;
                    e2=j;
                }
                d[i][j]=INT_MAX;
            }
        }
    deque<ii> q;
    d[s1][s2]=0;
    for (int i=0;i<4;i++)
    {
        int x=s1+dx[i];
        int y=s2+dy[i];
        if (x>0 && x<=n && y>0 && y<=m)
        {
            d[x][y]=0;
            q.push_front({x,y});
        }
    }
    while (q.size())
    {
        ii u=q.front();
        q.pop_front();
        for (int i=0;i<4;i++)
        {
            int x=u.fi+dx[i];
            int y=u.se+dy[i];
            if ((x>0 && x<=n && y>0 && y<=m) && d[x][y]>d[u.fi][u.se]+(a[u.fi][u.se]!=b[i]))
            {
                d[x][y]=d[u.fi][u.se]+(a[u.fi][u.se]!=b[i]);
                if (a[u.fi][u.se]!=b[i])
                    q.push_back({x,y});
                else q.push_front({x,y});
            }
        }
    }
    cout<<d[e1][e2]<<"\n";
   /*for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            cout<<d[i][j]<<" ";
        cout<<"\n";
    }*/
    return 0;
}
