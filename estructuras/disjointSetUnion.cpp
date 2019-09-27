// Fast version, almost O(1). join by size.
class DSUFast {
    public:

        vector <int> parent;
        vector <int> size;

        DSUFast(int sz){
            size = vector<int>(sz, 1);
            parent.resize(sz);
            forn(i, sz)
                parent[i] = i;
        }

        int find(int v){
            if(v == parent[v])
                return v;
            return parent[v] = find(parent[v]);
        }

        void join(int u, int v){
            int oldComp = find(u);
            int newComp = find(v);

            if(oldComp != newComp){
                if(size[oldComp] > size[newComp])
                    swap(oldComp, newComp);

                parent[oldComp] = newComp;
                size[newComp] += size[oldComp];
            }
        }
};

// Slower version, O(log n) average join. Stores each component.

class DSUComp {
    public:

        vector <vector <int>> component;
        vector <int> myComp;

        DSUComp(int size){
            forn(i, size){
                myComp.pb(i);
                component.pb({i});
            }
        }

        int find(int v){
            return myComp[v];
        }

        void join(int u, int v){
            int oldComp = find(u);
            int newComp = find(v);

            if(component[oldComp].size() > component[newComp].size())
                swap(oldComp, newComp);

            for(int w : component[oldComp]){
                component[newComp].pb(w);
                myComp[w] = newComp;
            }

            component[oldComp].clear();
        }

        // Returns a reference!
        vector <int> &getComponent(int v){
            return component[find(v)];
        }
};
