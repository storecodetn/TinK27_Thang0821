#include<bits/stdc++.h>
using namespace std;
int t,n,a[16385];
long long sum[16385];
int Sol(int l,int r){
    if(l>r){
        return 0;
    }
    if((sum[r]-sum[l-1])%2){
        return 0;
    }
    int k=lower_bound(sum+1,sum+1+n,sum[l-1]+((sum[r]-sum[l-1])/2))-sum;
    if((sum[k]-sum[l-1])!=((sum[r]-sum[l-1])/2)){
        return 0;
    }
    return 1+max(Sol(l,k),Sol(k+1,r));
}
int main(){
    freopen("DSEQDIV2.inp","r",stdin);
    freopen("DSEQDIV2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        sum[0]=0;
        bool check=true;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=0){
                check=false;
            }
            sum[i]=sum[i-1]+a[i];
        }
        if(check==true){
            cout<<n-1<<"\n";
            continue;
        }
        cout<<Sol(1,n)<<"\n";
    }
}
