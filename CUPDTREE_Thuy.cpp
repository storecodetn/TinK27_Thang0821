#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,z,p[100005][25],d[100005];
long long a[100005],s[100005],c;
vector <int> e[200005];
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
void DFS(int u,int pa){
    for (int i=0; i<e[u].size(); i++){
        int v=e[u][i];
        if (v!=pa){
            d[v]=d[u]+1;
            p[v][0]=u;
            DFS(v,u);
        }
    }
}
void DFS2(int u,int pa){
    for (int i=0; i<e[u].size(); i++){
        int v=e[u][i];
        if (v!=pa){
            DFS2(v,u);
            s[u]+=s[v];
        }
    }
}
int main(){
    freopen("CUPDTREE.inp","r",stdin);
    freopen("CUPDTREE.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    for (int i=1; i<=n-1; i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    d[1]=1; p[1][0]=1; DFS(1,-1);
    Khoitao();
    cin>>m;
    for (int i=1; i<=m; i++){
        cin>>x>>y>>c;
        z=LCA(x,y);
        s[x]+=c; s[y]+=c;
        s[z]-=c;
        if (p[z][0]!=z) s[p[z][0]]-=c;
    }
    DFS2(1,-1);
    for (int i=1; i<=n; i++){
        cout<<a[i]+s[i]<<" ";
    }
}
