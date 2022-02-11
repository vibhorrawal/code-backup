// O(N) time | O(1) space
bool solve(string s) {
    int count[10] = {0};
    for(char c : s) count[c - '0']++;
    bool possible[10];
    bool pairFound = false;
    for(int i = 0; i < 10; i++) {
        possible[i] = count[i] % 3 == 0;
        if(not possible[i]) {
            if(pairFound) return false;

            if(count[i] < 2) return false;
            count[i] -= 2;
            if(count[i] % 3 != 0) return false;
            pairFound = true;
        }
    }
    return pairFound;
}

// same as above, but looks easier to read
bool checkMod3(int count[]) {
    for(int i = 0; i < 10; i++){
        if(count[i] % 3) return false;
    }
    return true;
}

bool solve(string s) {
    int count[10] = {0};
    for(char c : s) count[c - '0']++;
    for(int pair = 0; pair < 10; pair++){
        if(count[pair] < 2) continue;
        count[pair] -= 2;
        bool possible = checkMod3(count);
        count[pair] += 2;
        if(possible) return true;
    }
    return false;
}

// even cleaner
// O(N) time | O(1) space
bool solve(string s) {
    vector<int> count_of_position(3, 0);
    unordered_map<int,int> freq;
    for(char c : s) {
        int n = c - '0';
        freq[n]++;
    }
    for(auto [val, count] : freq) {
        count_of_position[count % 3]++;
    }

    return count_of_position[1] == 0 and count_of_position[2] == 1;
}