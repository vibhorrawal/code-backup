bool solve(vector<int>& rect0, vector<int>& rect1) {
    if(rect0[0] > rect1[0]) swap(rect0, rect1);

    if(rect0[0] < rect1[0] && rect1[0] < rect0[2] &&
        rect0[1] < rect1[3] && rect1[3] < rect0[3])
        return true;

    if(rect0[0] < rect1[0] && rect1[0] < rect0[2] &&
        rect0[1] < rect1[1] && rect1[1] < rect0[3])
        return true;
    if(rect0[0] < rect1[2] && rect1[2] < rect0[2] &&
        rect0[1] < rect1[3] && rect1[3] < rect0[3])
        return true;
    if(rect1[0] < rect0[0] && rect0[0] < rect1[2] &&
        rect1[1] < rect0[1] && rect0[1] < rect1[3])
        return true;
    if(rect1[0] < rect0[2] && rect0[2] < rect1[2] &&
        rect1[1] < rect0[3] && rect0[3] < rect1[3])
        return true;
    return false;
}

// better cleaner implementation
bool check_disjoint(vector<int> a, vector<int> b){
    for(int rep = 0; rep < 2; rep++){
        int ax0 = a[0], ay0 = a[1], ax1 = a[2], ay1 = a[3];
        int bx0 = b[0], by0 = b[1], bx1 = b[2], by1 = b[3];
        if(max(ax0, ax1) <= min(bx0, bx1) or max(ay0, ay1) <= min(by0, by1))
            return true;
        swap(a, b);
    }
    return false;
}

bool solve(vector<int>& rect0, vector<int>& rect1) {
    return not check_disjoint(rect0, rect1);
}
