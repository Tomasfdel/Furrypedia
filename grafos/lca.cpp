// Lowest Common Ancestor with Binary Lifting

// Given a global graph vector<int> G[N] with N nodes;
class LCA{
	public:
		int timer;
		int logN;
		vector<int> tIn, tOut;
		// up[v][k] stores the 2**k ancestor of v
		vector<vector<int>> up;

		LCA(int root = 0){
			timer = 0;
			tIn.resize(N);
			tOut.resize(N);
			logN = ceil(log2(N));
			up.assign(N, vector<int>(logN + 1));
			dfs(root, root);
		}

		void dfs(int v, int p){
			tIn[v] = timer++;
			up[v][0] = p;
			forn(i, logN)
				up[v][i+1] = up[ up[v][i] ][i];

			for(int w : G[v])
				if(w != p)
					dfs(w, v);

			tOut[v] = timer++;
		}

		// Is u an ancestor of v?
		bool isAncestor(int u, int v){
			return tIn[u] <= tIn[v] and tOut[u] >= tOut[v];
		}

		int lca(int u, int v){
			if(isAncestor(u, v))
				return u;
			if(isAncestor(v, u))
				return v;

			dforn(i, logN+1)
				if(not isAncestor(up[u][i], v))
					u = up[u][i];

			return up[u][0];
		}
};
