// AC - https://codeforces.com/problemset/problem/27/B

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

#define forr(i,x,n) for(int i=(x); i<int(n); i++)
#define forn(i,n) forr(i,0,n)
#define fst first
#define snd second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 1e5 + 5;
const ll INF = 1e16 + 5;
const ll MOD = 1e9 + 7;

vector<int> G[MAXN]; int N;
vector<int> tsort(){
    vector<int> R, D(2*N, 0);
    priority_queue<int> Q;
    forn(i,N) for(auto &v : G[i]) D[v]++;
    forn(i,N) if(!D[i]) Q.push(-i);
    while(!Q.empty()){
        int x = -Q.top(); Q.pop(); R.pb(x);
        for(auto &v : G[x]) if(!--D[v]) Q.push(-v);
    }
    return R; // G not DAG => R has less than N elements
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    
    cin >> N;
    set<pii> seen;
    forn(i,N*(N-1)/2 - 1){
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[x].pb(y);
        seen.insert({min(x,y),max(x,y)});
    }
    
    auto getboi = [&](){ 
        forn(i,N) forr(j,i+1,N)
            if(!seen.count({i,j}))
                return pair<int,int>(i, j);
        return pair<int,int>(-1, -1);
    };
    
    auto order = tsort();
    pii miss = getboi(), ans;
    
    for(auto &v : order){
        if(v == miss.fst){
            ans = {miss.fst+1, miss.snd+1};
            break;
        }
        if(v == miss.snd){
            ans = {miss.snd+1, miss.fst+1};
            break;
        }
    }
    
    cout << ans.fst << ' ' << ans.snd << endl;

    return 0;
}
