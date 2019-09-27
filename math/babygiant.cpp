int babygiant(int a, int b, int m){
    // O( sqrt(m) * log(m) ), solves a ^ x = b (mod m)
	int n = (int) sqrt(m+.0)+1;
	int an = 1;
	forn(i,n) an = (an * a) % m;

	map<int,int> vals;
	for(int i=1, cur=an; i<=n; ++i){
		if(!vals.count(cur))
            vals[cur] = i;
		cur = (cur * an) % m;
	}

	for(int i=0, cur=b; i<=n; ++i){
		if(vals.count(cur)){
			int ans = vals[cur] * n - i;
			if (ans < m)
				return ans;
		}
		cur = (cur * a) % m;
	}
	return -1;
}
