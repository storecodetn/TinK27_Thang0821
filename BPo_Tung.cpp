#include <bits/stdc++.h>
using namespace std;
int n,a[100001],st[4*100000+10],jump[100001];
map<int,int> ma;
void add(int id,int l,int r,int pos,int val)
{
    if(l>pos || pos>r)
        return;
    if(l==r)
    {
        st[id]=val;
        return;
    }
    int mid=(l+r)/2;
    add(id*2,l,mid,pos,val);
    add(id*2+1,mid+1,r,pos,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int L,int R)
{
    if(L>r || R<l)
        return INT_MAX;
    if(L<=l && r<=R)
        return st[id];
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,L,R),get(id*2+1,mid+1,r,L,R));
}
int xuly(int l,int r)
{
    if(l>r)
        return 0;
    int Min=get(1,1,n,l,r);
    int chot=ma[Min];
    while(chot<l)
        chot=jump[chot];
    int ans=0;
    int last;
    last=l-1;
    while(chot<=r && chot!=0)
    {
        ans+=xuly(last+1,chot-1);
        last=chot;
        chot=jump[chot];
    }
    ans+=xuly(last+1,r);
    return ans+1;
}
int main()
{
    freopen("BPo.inp","r",stdin);
    freopen("BPo.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            add(1,1,n,i,a[i]);
        }
    for(int i=n;i>=1;i--)
    {
        jump[i]=ma[a[i]];
        ma[a[i]]=i;
    }
    cout<<xuly(1,n)-(get(1,1,n,1,n)==0?1:0);
}
