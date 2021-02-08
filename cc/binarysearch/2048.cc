void right(vector<vector<int>>& a){
    for(int r = 0; r < a.size(); r++){
        deque<int> dq;
        bool used = false;
        for(int c = 3; c >= 0; c--){
            if(a[r][c]) {
                if((not used) and dq.size() and dq.front() == a[r][c]){
                    dq.pop_front();
                    dq.push_front(2 * a[r][c]);
                    used = true;
                }
                else {
                    dq.push_front(a[r][c]);
                    used = false;
                }
            }
        }
        for(int c = 3; c >= 0; c--){
            if(dq.size()){
                a[r][c] = dq.back(); dq.pop_back();
            }
            else a[r][c] = 0;
        }
    }
}

void down(vector<vector<int>>& a) {
    for(int c = 0; c < 4; c++){
        deque<int> dq;
        bool used = false;
        for(int r = 3; r >= 0; r--){
            if(a[r][c]) {
                if((not used) and dq.size() and dq.front() == a[r][c]){
                    dq.pop_front();
                    dq.push_front(2 * a[r][c]);
                    used = true;
                }
                else {
                    dq.push_front(a[r][c]);
                    used = false;
                }
            }
        }
        for(int r = 3; r >= 0; r--){
            if(dq.size()){
                a[r][c] = dq.back(); dq.pop_back();
            }
            else a[r][c] = 0;
        }
    }
}

void up(vector<vector<int>>& a) {
    for(int c = 0; c < 4; c++){
        deque<int> dq;
        bool used = false;
        for(int r = 0; r < 4; r++){
            if(a[r][c]) {
                if((not used) and dq.size() and dq.front() == a[r][c]){
                    dq.pop_front();
                    dq.push_front(2 * a[r][c]);
                    used = true;
                }
                else {
                    dq.push_front(a[r][c]);
                    used = false;
                }
            }
        }
        for(int r = 0; r < 4; r++){
            if(dq.size()){
                a[r][c] = dq.back(); dq.pop_back();
            }
            else a[r][c] = 0;
        }
    }
}
vector<vector<int>> solve(vector<vector<int>>& a, string dir) {
    if(dir == "right"){
        right(a);
    }
    if(dir == "left"){
        for(int r = 0; r < 4; r++){
            reverse(a[r].begin(), a[r].end());
        }
        right(a);
        for(int r = 0; r < 4; r++){
            reverse(a[r].begin(), a[r].end());
        }
    }
    if(dir == "down"){
        down(a);
    }
    if(dir == "up"){
        up(a);
    }
    return a;
}


//------------------------------------------------
// O(n^2) time and space
enum direction { RIGHT, DOWN, LEFT, UP };
int string_code(string &s) {
    if (s == "left") return LEFT;
    if (s == "right") return RIGHT;
    if (s == "up") return UP;
    if (s == "down") return DOWN;
    assert(false);
}

void rotate_cw(vector<vector<int>> &b) {
    int n = b.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < n; j++, k--) {
            res[i][j] = b[k][i];
        }
    }
    swap(res, b);
}

void solve_for_right(vector<vector<int>> &b) {
    int n = b.size();
    for (int r = 0; r < n; r++) {
        vector<int> row;
        bool combined_last = false;
        for (int c = n - 1; c >= 0; c--) {
            if (b[r][c]) {
                if (row.size() and row.back() == b[r][c] and not combined_last) {
                    row.back() += b[r][c];
                    combined_last = true;
                } else {
                    row.push_back(b[r][c]);
                    combined_last = false;
                }
            }
        }
        int c = n - 1;
        for (int j = 0; j < row.size(); j++, c--) b[r][c] = row[j];
        for (; c >= 0; c--) b[r][c] = 0;
    }
}

vector<vector<int>> solve(vector<vector<int>> &b, string d) {
    switch (string_code(d)) {
        case DOWN:
            rotate_cw(b);
        case LEFT:
            rotate_cw(b);
        case UP:
            rotate_cw(b);
    }

    solve_for_right(b);

    switch (string_code(d)) {
        case UP:
            rotate_cw(b);
        case LEFT:
            rotate_cw(b);
        case DOWN:
            rotate_cw(b);
    }

    return b;
}
