#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],cnt=0,id;
deque <int> d;
int main(){
    freopen("BPo.inp","r",stdin);
    freopen("BPo.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    for (int i=1; i<=n; i++){
        if (a[i]>0){
            cnt++; d.push_back(i); id=i;
            break;
        }
    }
    for (int i=id+1; i<=n; i++){
        while(d.size()>0 && a[d.back()]>a[i]) d.pop_back();
        if (a[i]==0){ continue;}
        else{
            if (d.size()==0) cnt++;
            else{
                if (a[d.back()]<a[i]) cnt++;
            }
            d.push_back(i);
        }
    }
    cout<<cnt;
}
