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
