// O(NM) space time
vector<vector<int>> a;
set<int> dig = {1,2,3,4,5,6,7,8,9};

bool check_row(int r){
    set<int> s;
    for(int c = 0; c < a[0].size(); c++){
        int x = a[r][c];
        if(s.count(x)) return false;
        s.insert(x);
    }
    return s == dig;
}

bool check_col(int c){
    set<int> s;
    for(int r = 0; r < a.size(); r++) {
        int x = a[r][c];
        if(s.count(x)) return false;
        s.insert(x);
    }
    return s == dig;
}

bool check_box(int x, int y){
    set<int> s;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int r = x * 3 + i;
            int c = y * 3 + j;
            
            int xx = a[r][c];
            // if(x == 2 and y == 2) cout<<xx<<' ';
            if(s.count(xx)) return false;
            s.insert(xx);
        }
    }
    return s == dig;
}

bool solve(vector<vector<int>>& matrix) {
    a = matrix;
    bool valid = true;
    for(int r = 0; r < a.size(); r++) {
        valid &= check_row(r);
    }
    for(int c = 0; c < a[0].size(); c++){
        valid &= check_col(c);
    }
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            valid &= check_box(x,y);
        }
    }
    return valid;
}
