// AC - https://codeforces.com/contest/20/submission/47280560
vector<pll> G[MAXN];  // u->[(v,cost)]
ll dist[MAXN], dad[MAXN];
void dijkstra(ll x){
	memset(dist,-1,sizeof(dist));
	memset(dad,-1,sizeof(dad));
	priority_queue<pll> Q;
	dist[x]=0; Q.push({0,x});
	while(!Q.empty()){
		x=Q.top().snd; ll c=-Q.top().fst; Q.pop();
		if(dist[x]!=c)continue;
		forn(i,G[x].size()){
			ll y=G[x][i].fst, c=G[x][i].snd;
			if(dist[y]<0 || dist[x]+c<dist[y])
				dist[y]=dist[x]+c, Q.push({-dist[y],y}), dad[y]=x;
		}
	}
}
