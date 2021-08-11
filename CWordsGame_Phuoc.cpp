#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 100, mod1 = 1e9 + 7, mod2 = 1e9 + 9, base1 = 33, base2 = 37;
typedef pair<long long, long long> dll;
int numBi, numDen;
string Bi[maxn], Den[maxn];
map <dll,set<dll>> stoBi,stoDen;

void processBi(string s)
{
    long long h1 = 0,h2  = 0, lasth1, lasth2;
    for(int i = 0; i < (int) s.size(); i++)
    {
        lasth1 = h1, lasth2 = h2;
        h1 = (h1 * base1 + s[i] - 'a' + 1) % mod1;
        h2 = (h2 * base2 + s[i] - 'a' + 1) % mod2;
        stoBi[{lasth1,lasth2}].insert({h1,h2});
    }
}

void processDen(string s)
{
    long long h1 = 0,h2  = 0, lasth1, lasth2;
    for(int i = 0; i < (int) s.size(); i++)
    {
        lasth1 = h1, lasth2 = h2;
        h1 = (h1 * base1 + s[i] - 'a' + 1) % mod1;
        h2 = (h2 * base2 + s[i] - 'a' + 1) % mod2;
        stoDen[{lasth1, lasth2}].insert({h1,h2});
    }
}

bool getAns(int num, long long h1, long long h2)
{
    bool ans;
    if(num%2)
    {
        ans = 0;
        if(stoBi[{h1,h2}].empty()) return false;
        for(auto val : stoBi[{h1,h2}])
        {
            ans |= getAns(num + 1, val.first, val.second);
            if(ans) return ans;
        }
        return ans;
    }
    else
    {
        ans = 1;
        if(stoDen[{h1,h2}].empty()) return true;
        for(auto val : stoDen[{h1,h2}])
        {
            ans &= getAns(num + 1, val.first, val.second);
            if(!ans) return ans;
        }
        return ans;
    }
}

int main()
{
    freopen("CWordsGame.inp","r",stdin);
    freopen("CWordsGame.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> numBi;
    for(int i = 1; i <= numBi; i++) cin >> Bi[i];

    cin >> numDen;
    for(int i = 1; i <= numDen; i++) cin >> Den[i];

    for(int i = 1; i <= numBi; i++) processBi(Bi[i]);

    for(int i = 1; i <= numDen; i++) processDen(Den[i]);

    if(getAns(1, 0ll, 0ll)) cout << "Bi";
    else cout << "Den";

}
