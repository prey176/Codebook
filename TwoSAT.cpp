struct TwoSat {
    int n;
    int NUM_VERTICES, id;
    vector<int> arr;
    vector<vector<int>> adj;
    vector<bool> mark;
 
    TwoSat(int n) : n(n), adj(2 * n + 2), NUM_VERTICES(2 * n), mark(2 * n + 2), arr(2 * n + 2) {}
 
    inline bool dfs(int node) {
        if (mark[node ^ 1]) {
            return false;
        }
        if (mark[node]) {
            return true;
        }
        mark[node] = true;
        arr[id++] = node;
        for (int i = 0; i < (int) adj[node].size(); i++) {
            if (!dfs(adj[node][i])) {
                return false;
            }
        }
        return true;
    }
 
    // Adds the clause (u or v) to the set of clauses
    inline void addOr(int u, int v) {
        adj[u ^ 1].emplace_back(v);
        adj[v ^ 1].emplace_back(u);
    }
 
    // Adds the clause (u == v) to the set of clauses
    inline void addEquivalent(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        adj[u ^ 1].emplace_back(v ^ 1);
        adj[v ^ 1].emplace_back(u ^ 1);
    }
 
    // Adds the clause (u xor v) to the set of clauses
    inline void addXor(int u, int v) {
        addOr(u, v);
        addOr(u ^ 1, v ^ 1);
    }
 
    // Forces variable (u) to be true
    inline void forceTrue(int u) {
        adj[u ^ 1].emplace_back(u);
    }
 
    // Forces variable (u) to be false
    inline void forceFalse(int u) {
        adj[u].emplace_back(u ^ 1);
    }
 
    // Adds the clause (u and v) to the set of clauses
    inline void addAnd(int u, int v) {
        forceTrue(u);
        forceTrue(v);
    }
 
    inline void addImplication(int u, int v) {
        adj[u].emplace_back(v);
    }
 
    // Returns true if a solution exists.
    inline bool solve() {
        for (int i = 0; i < NUM_VERTICES; i++) {
            sort(adj[i].begin(), adj[i].end());
            adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
        }
        for (int i = 0; i < NUM_VERTICES; i += 2) {
            if ((!mark[i]) && (!mark[i + 1])) {
                id = 0;
                if(!dfs(i)) {
                    while (id > 0) {
                        mark[arr[--id]] = false;
                    }
                    if(!dfs(i + 1)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
