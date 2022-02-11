// O(n * log(n)) space time for creation; O(log(n)) for getting k-th
class TreeAncestor {
public:
    int LOG;
    vector<vector<int>> u;
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while((1<<LOG) <= n) LOG++;
        LOG++;
        u = vector<vector<int>>(n, vector<int>(LOG, -1));
        for(int i = 0; i < n; i++) 
            u[i][0] = parent[i];
        
        for(int j = 1; j < LOG; j++) {
            for(int i = 0; i < n; i++) {
                int me = u[i][j-1];
                if(me != -1)
                    u[i][j] = u[ me ][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int bit = 0; bit < LOG && node != -1; bit++) {
            if(k & (1 << bit)) {
                node = u[node][bit];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */