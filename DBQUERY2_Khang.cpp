#include<bits/stdc++.h>
using namespace std;
int n,m,q,cntd[2001][2001],cnten[2001][2001],cnted[2001][2001];
char c[2001][2001];
int main(){
    freopen("DBQUERY2.inp","r",stdin);
    freopen("DBQUERY2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cntd[i][j]=cntd[i-1][j]+cntd[i][j-1]-cntd[i-1][j-1]+(c[i][j]=='1');
            cnten[i][j]=cnten[i-1][j]+cnten[i][j-1]-cnten[i-1][j-1]+(c[i][j]==c[i][j-1] && c[i][j]=='1');
            cnted[i][j]=cnted[i-1][j]+cnted[i][j-1]-cnted[i-1][j-1]+(c[i-1][j]==c[i][j] && c[i][j]=='1');
        }
    }
    while(q--){
        int u,v,p,q;
        cin>>u>>v>>p>>q;
        cout<<(cntd[p][q]-cntd[u-1][q]-cntd[p][v-1]+cntd[u-1][v-1])-(cnten[p][q]-cnten[u-1][q]-cnten[p][v]+cnten[u-1][v])-(cnted[p][q]-cnted[u][q]-cnted[p][v-1]+cnted[u][v-1])<<"\n";
    }
}
