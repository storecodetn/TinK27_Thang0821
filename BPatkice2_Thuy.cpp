#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,m,sx,sy,ex,ey;
short dr[4]={0,0,1,-1}; short dc[4]={1,-1,0,0};
typedef pair <int,int> ii;
deque <ii> dq;
int main(){
    /*freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);*/
    freopen("BPatkice2.inp","r",stdin);
    freopen("BPatkice2.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    char a[n+3][m+3]; int d[n+3][m+3];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin>>a[i][j];
            if (a[i][j]=='o'){ sx=i; sy=j;};
            if (a[i][j]=='x'){ ex=i; ey=j;};
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            d[i][j]=1e8;
        }
    }
    d[sx][sy]=0; dq.push_back(ii(sx,sy));
    while(dq.size()){
        int u=dq.front().fi; int v=dq.front().se; dq.pop_front();
        if (u==ex && v==ey) continue;
        for (int i=0; i<4; i++){
            int p=u+dr[i]; int q=v+dc[i];
            if (1<=p && p<=n && 1<=q && q<=m){
                if((a[u][v]=='^' && i==3) || (a[u][v]=='v' && i==2) || (a[u][v]=='>' && i==0) || (a[u][v]=='<' && i==1) || a[u][v]=='o' || a[u][v]=='x'){
                    if (d[p][q]>d[u][v]){
                        d[p][q]=d[u][v];
                        dq.push_front(ii(p,q));
                    }
                }
                else{
                    if (d[p][q]>d[u][v]+1){
                        d[p][q]=d[u][v]+1;
                        dq.push_back(ii(p,q));
                    }
                }
            }
        }
    }
    cout<<d[ex][ey];
}
