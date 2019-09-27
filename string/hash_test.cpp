//~ http://codeforces.com/contest/727/submission/51942932

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <chrono>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>

#define forr(i,x,n) for(int i=x; i<int(n); i++)
#define forn(i,n) forr(i,0,n)

#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define SZ(v) ((int) v.size())

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e9 + 2;

int N, K, M;

struct Hash {
	int p = 1777771, mod[2], pInv[2];
	//~ h[k][i] = hash[k]( s[0, i) )
	//~ p**i * potInv[k][i] = 1 modulo mod[k]
	vector<int> h[2],potInv[2];
	Hash(string& s){
		mod[0] = 999727999; mod[1] = 1070777777;
		//~ Modular inverse of p
		pInv[0] = 325255434; pInv[1] = 10018302;
		forn(k,2){
			h[k].resize(s.size()+1);
			potInv[k].resize(s.size()+1);
		}
		forn(k,2){
			h[k][0] = 0;
			potInv[k][0] = 1;
			ll pAcum = 1;
			forr(i, 1, s.size()+1){
				h[k][i] = (h[k][i-1] + pAcum * s[i-1]) % mod[k];
				potInv[k][i] = (1LL * potInv[k][i-1] * pInv[k]) % mod[k];
				pAcum = (pAcum * p) % mod[k];
			}
		}
	}
	//~ get(i, j) = hash( s[i,j) )
	ll get(int s, int e){
		ll hashes[2];
		forn(k, 2){
			hashes[k] = (h[k][e] - h[k][s] + mod[k]) % mod[k];
			hashes[k] = (1LL * hashes[k] * potInv[k][s]) % mod[k];
		}
		return (hashes[0]<<32)|hashes[1];
	}
};

const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    ll operator()(ll x) const { return x ^ RANDOM; }
};
gp_hash_table<ll, ll, chash> table;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.in", "r", stdin);
	cin>>N>>K;
	string s1;
	cin>>s1;
	s1 += s1.substr(0, K);
	
	cin>>M;
	forn(i, M){
		string s2;
		cin>>s2;
		Hash h(s2);
		ll hashRet = h.get(0, K);
		table[hashRet] = i+1;
	}
	
	Hash h(s1);
	forn(start, K){
		gp_hash_table<ll, ll, chash> used;
		vector <int> ans;
		
		forn(i, N){
			ll startInd = start + K*i;
			ll hashRet = h.get(startInd, startInd + K);
			auto it = table.find(hashRet);
			if(it == table.end() or used.find(it->first) != used.end()){
				break;
			}
				
			ans.pb(it->second);
			used[it->first] = it->first;
		}
		
		if(int(ans.size()) == N){
			cout<<"YES\n"<<ans[0];
			forr(i, 1, N)
				cout<<' '<<ans[i];
			cout<<"\n";
			return 0;
		}
	}
	
	cout<<"NO\n";
	
    return 0;
}
