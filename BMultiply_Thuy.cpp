#include <bits/stdc++.h>
using namespace std;
const int MAX=10000001;
int x,y,z,t,q;
bool p[10000005];
vector <int> ps;
int get(int n, int prime){
    int ans=0;
    for (long long i=prime; i<=n; i*=prime){
        ans+=(n/i);
    }
    return ans;
}
bool xuly(int a, int b, int c, int d){
    if (a==1) a=2;
    if (c==1) c=2;
    bool checker=0;
    for (int i=0; i<ps.size(); i++){
        int prime=ps[i];
        int dd=get(d,prime);
        int dc=get(c-1,prime);
        int db=get(b,prime);
        int da=get(a-1,prime);
        int ans=dd+da-(dc+db);
        if (ans<0){
            checker=1; break;
        }
    }
    return checker;
}
int main(){
    freopen("BMultiply.inp","r",stdin);
    freopen("BMultiply.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>q;
    for (int i=2; i*i<=MAX; i++){
        if (p[i]==0){
            for (int j=i*i; j<=MAX; j+=i){
                p[j]=1;
            }
        }
    }
    for (int i=2; i<=MAX; i++){
        if (p[i]==0) ps.push_back(i);
    }
    while(q--){
        cin>>x>>y>>z>>t;
        bool ok=xuly(x,y,z,t);
        if (ok==0) cout<<"Y"<<"\n";
        else cout<<"N"<<"\n";
    }
}
