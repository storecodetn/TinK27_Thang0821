#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,k,l[1000005],r[1000005],ans;
typedef pair <int,int> ii;
ii a[1000005];
long long res=0;
int getleft(int u){
    if (l[u]==u) return u;
    return l[u]=getleft(l[u]);
}
int getright(int u){
    if (r[u]==u) return u;
    return r[u]=getright(r[u]);
}
int main(){
    freopen("DRoad.inp","r",stdin);
    freopen("DRoad.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1; i<n; i++){
        cin>>a[i].fi;
        a[i].se=i;
        l[i]=i; r[i]=i;
    }
    l[n]=n; r[n]=n;
    sort(a+1,a+n);
    for (int i=1; i<n; i++){
        int id=a[i].se; int w=a[i].fi;
        l[id+1]=l[getleft(id)]; r[id]=r[getright(id+1)];
        int len=0; int le=id-getleft(id); int ri=getright(id+1)-(id+1);
        while(true){
            len++;
            if (w>=len+k){
                int o=len-1;
                if (le+ri>=o){
                    ans=len;
                    if (o>=le){
                        ans-=(o-le);
                    }
                    if (o>=ri){
                        ans-=(o-ri);
                    }
                    if (ans>0) res+=ans;
                }
                else break;
            }
            else break;
        }
    }
    res=res*2;
    cout<<res;
}
