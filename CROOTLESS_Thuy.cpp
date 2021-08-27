#include <bits/stdc++.h>
using namespace std;
int n,q,x,y,r,d[100005],p[100005][20];
vector <int> e[100005];
int LCA(int u, int v){
    for (int j=19; j>=0; j--){
        if(d[p[u][j]]>=d[v]){
            u=p[u][j];
        }
    }
    for (int j=19; j>=0; j--){
        if(d[u]<=d[p[v][j]]){
            v=p[v][j];
        }
    }
    for(int i=19; i>=0; i--){
        if(p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    while(u!=v){
        u=p[u][0];
        v=p[v][0];
    }
    return u;
}
void Khoitao(){
    for (int j=1; j<=19; j++){
        for (int i=1; i<=n; i++){
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
}
void DFS(int u, int pa){
    for (int i=0; i<e[u].size(); i++){
        int v=e[u][i];
        if (v!=pa){
            d[v]=d[u]+1;
            p[v][0]=u;
            DFS(v,u);
        }
    }
}
int main(){
    freopen("CROOTLESS.inp","r",stdin);
    freopen("CROOTLESS.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<n; i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    d[1]=1; p[1][0]=1;
    DFS(1,-1);
    Khoitao();
    cin>>q;
    while(q--){
        cin>>r>>x>>y;
        if (r==1) cout<<LCA(x,y)<<"\n";
        else{
            int a=LCA(r,x);
            int b=LCA(r,y);
            if (a==b){
                int c=LCA(x,y);
                cout<<c<<"\n";
            }
            else{
                if (abs(d[a]-d[r])<=abs(d[b]-d[r])) cout<<a<<"\n";
                else cout<<b<<"\n";
            }
        }
    }
}
