class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(next_permutation(s.begin(), s.end())) return stol(s) >= INT_MAX ? -1 : stoi(s);
        return -1;
    }
};

// O(n) time | O(1) space
class Solution {
public:
    int nextGreaterElement(int n) {
        int i;
        string s = to_string(n);
        for(i = s.size()-1; i > 0; i--)
            if(s[i-1] < s[i]) break;

        if(i == 0) return -1;

        int st = i-1, smallest = i;
        for(int j = i; j < s.size(); j++){
            if(s[j] <= s[smallest] and s[j] > s[st]) smallest = j;
        }
        swap(s[st], s[smallest]);
        reverse(s.begin() + i, s.end()); // sort()
        long l = stol(s);
        return l >= INT_MAX ? -1 : l;
    }
};
