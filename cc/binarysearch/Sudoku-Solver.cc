// O(NM * NUMSIZE) space time; NUMSIZE is 9 here; technically its all O(1)
vector<vector<int>> a;
int n, m;
vector<pair<int,int>> p;
unordered_set<int> row[9], col[9];

bool check_row(int r, int val){
    return not row[r].count(val);
    for(int c = 0; c < m; c++) if(a[r][c] == val) return false;
    return true;
}

bool check_col(int c, int val){
    return not col[c].count(val);
    for(int r = 0; r < m; r++) if(a[r][c] == val) return false;
    return true;
}

bool check_box(int i, int j, int val){
    int x = i/3, y = j/3;
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            if(a[r + x * 3][c + y * 3] == val) return false;
        }
    }
    return true;
}
bool valid(int r, int c, int val) {
    return check_row(r, val)
    and check_col(c, val)
    and check_box(r,c,val);
}

bool dfs(int x){
    if(x == p.size()) 
        return true;
    int i = p[x].first, j = p[x].second;
    for(int k = 1; k <= 9; k++){
        if(not valid(i,j,k)) continue;
        a[i][j] = k;
        row[i].insert(k); col[j].insert(k);
        if(dfs(x + 1))
            return true;
        row[i].erase(k); col[j].erase(k);
        a[i][j] = 0;
    }
    return false;
}
vector<vector<int>> solve(vector<vector<int>>& a_) {
    for(int i = 0; i < 9; i++) {
        row[i].clear();
        col[i].clear();
    }
    p.clear();
    a = a_;
    n = a.size(), m = a[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0)
                p.push_back({i,j});
            else{
                row[i].insert(a[i][j]); 
                col[j].insert(a[i][j]);
            }
        }
    }
    int x = 0;
    int i = p[x].first, j = p[x].second;
    for(int k = 1; k <= 9; k++){
        if(not valid(i,j,k)) 
            continue;
        a[i][j] = k;
        row[i].insert(k); col[j].insert(k);
        if(dfs(1)) return a;
        a[i][j] = 0;
        row[i].erase(k); col[j].erase(k);
    }
    assert(false);
    return a;
}

// same as above, but much cleaner
vector<vector<int>> ans;

inline int getIdx(int i, int j) {
    return (i / 3) * 3 + (j / 3);
}

void dfs(
    vector<vector<int>> &m, 
    vector<pair<int,int>> &empty, 
    int pos, 
    vector<unordered_set<int>>& row, 
    vector<unordered_set<int>>& col, 
    vector<unordered_set<int>>& box) {
    if(ans.size()) {
        return;
    }

    if(pos == empty.size()) {
        // by the way that sudoku is built, it is always possible if i/p is valid
         ans = m;
        return;
    }
    
    auto [r, c] = empty[pos];
    for(int num = 1; num <= 9; num++) {
        if(row[r].count(num) or col[c].count(num) or box[getIdx(r, c)].count(num)) continue;
        row[r].insert(num);
        col[c].insert(num);
        box[getIdx(r, c)].insert(num);

        m[r][c] = num;
        dfs(m, empty, pos + 1, row, col, box);

        row[r].erase(num);
        col[c].erase(num);
        box[getIdx(r, c)].erase(num);
    }
}

vector<vector<int>> solve(vector<vector<int>>& m) {
    ans = vector<vector<int>>();
    vector<pair<int,int>> empty;
    vector<unordered_set<int>> row(9), col(9), box(9);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(m[i][j] == 0) empty.push_back({i, j});
            else {
                row[i].insert(m[i][j]);
                col[j].insert(m[i][j]);
                box[getIdx(i,j)].insert(m[i][j]);
            }
        }
    }

    dfs(m, empty, 0, row, col, box);
    return ans;
}