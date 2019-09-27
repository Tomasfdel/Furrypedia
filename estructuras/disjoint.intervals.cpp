// AC - https://codeforces.com/contest/27/submission/47281082
struct disjoint_intervals{ // intervals [first, second)
	set<pll> s;
	void insert(pll v){
		if(v.fst>=v.snd) return;
		auto at=s.lower_bound(v), it=at;
		if(at!=s.begin()&&(--at)->snd>=v.fst) v.fst=at->fst, --it;
		for(;it!=s.end()&&it->fst<=v.snd;s.erase(it++))
			v.snd=max(v.snd,it->snd);
		s.insert(v);
	}
};
