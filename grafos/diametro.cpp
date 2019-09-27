// AC - https://codeforces.com/contest/1092/submission/47239653
int N, M;
vector<int> G[MAXN], p(MAXN), df(MAXN), ds(MAXN);
int bfs(int r, vector<int>& d){
    queue<int> Q;
    Q.push(r); d[r] = 0;
    int v;
    while(Q.size()){
        v = Q.front(); Q.pop();
        for(auto &e : G[v]) if(d[e] == -1)
            d[e] = d[v]+1, p[e] = v, Q.push(e);
    }
    return v; //last visited node
}
vector<int> diams; vector<pii> centers;
void get_diams(){
	fill(df.begin(), df.end(), -1);
	fill(ds.begin(), ds.end(), -1);
	diams.clear(), centers.clear();
	int v, c;
	forn(i, N) if(df[i] == -1){
		c = v = bfs(bfs(i, ds), df);
		forn(_, df[v]/2) c = p[c];
		diams.pb(df[v]);
		centers.pb({c, df[v]&1 ? p[c] : c});
	}
}
