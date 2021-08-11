#include <bits/stdc++.h>
using namespace std;
int ans,n,m;
struct trie{
    trie *child[30];
    int Count;
};
trie* newNode()
{
    trie *node=new trie;
    for(int i=0;i<=25;i++)
    {
        node->child[i]=NULL;
        node->Count=0;
    }
    return node;
}
void Insert(trie *root,string k)
{
    trie *node=root;
    for(int i=0;i<k.size();i++)
    {
        if(!node->child[k[i]-'a'])
            node->child[k[i]-'a']=newNode();
        node=node->child[k[i]-'a'];
        node->Count++;
    }
}
int xuly(trie *root1,trie *root2,int x)
{
        int winner;
        if(x%2==1)
            winner=2;
        else
            winner=1;
        for(int i=0;i<=25;i++)
        {
            if(x%2==1)
            {
                if(!root2->child[i] && root1->child[i])
                    return 1;
                if(root1->child[i])
                    winner=min(winner,xuly(root1->child[i],root2->child[i],x+1));
            }
            else
            {
                if(!root1->child[i] && root2->child[i])
                    return 2;
                if(root2->child[i])
                    winner=max(winner,xuly(root1->child[i],root2->child[i],x+1));
            }
        }
        return winner;
}
int main()
{
    freopen("CWordsGame.inp","r",stdin);
    freopen("CWordsGame.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    trie *root1=newNode();
    trie *root2=newNode();
    for(int i=1;i<=n;i++)
    {
        string t;
        cin>>t;
        Insert(root1,t);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        string t;
        cin>>t;
        Insert(root2,t);
    }
    ans=xuly(root1,root2,1);
    if(ans%2==1)
        cout<<"Bi";
    else
        cout<<"Den";
}
