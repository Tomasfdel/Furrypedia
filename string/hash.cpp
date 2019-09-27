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
