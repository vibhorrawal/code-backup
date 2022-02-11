// O(N) space time
vector<int> solve(vector<int>& a) {
    unordered_map<int,int> freq;
    for(int x : a) freq[x]++;
    int n = a.size() / 3;
    vector<int> res;
    for(auto [x,c] : freq){
        if(c > n) res.push_back(x);
    }
    sort(res.begin(), res.end());
    return res;
}

// O(NlogN) time | O(1) space
vector<int> solve(vector<int>& a) {
    sort(a.begin(), a.end());
    const int n = a.size();
    vector<int> res;
    for(int i = 0; i < n;) {
        int cnt = 0;
        while(i+cnt < n and  a[i] == a[i+cnt]) cnt++;
        if(cnt > n/3) res.push_back(a[i]);
        i += cnt;
    }   
    return res;
}

// O(1) space | O(N) time
// Moores Voting Algorithm
vector<int> solve(vector<int>& a) {
    int candidate1, count1 = 0, candidate2, count2 = 0;
    for(int x : a){
        if(count1 == 0){
            candidate1 = x;
            count1++;
        }
        else if(candidate1 == x){
            count1++;
        }
        else if(count2 == 0){
            candidate2 = x;
            count2++;
        }
        else if(candidate2 == x){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    vector<int> res;
    int n = a.size();
    count1 = count2 = 0;
    for(int x : a){
        if(candidate1 == x) count1++;
        if(candidate2 == x) count2++;
    }
    if(count1 > n/3) res.push_back(candidate1);
    if(count2 > n/3 and candidate1 != candidate2) res.push_back(candidate2);
    sort(res.begin(), res.end());

    return res;
}

// apparently failed on
//  [2, 1, 1, 3, 1, 4, 5, 6]