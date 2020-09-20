// O(n) time | O(n) space
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string sub;
        int pos = 0;
        unordered_map<string, string> mapIdx;
        while(getline(ss, sub, ' ')){
            string pat = to_string(pattern[pos]);
            
            if(mapIdx.find(pat) == mapIdx.end())
                mapIdx[pat] = pos;
            if(mapIdx.find(sub) == mapIdx.end())
                mapIdx[sub] = pos;
            if(mapIdx[sub] != mapIdx[pat])
                return false;
            pos++;
        }
        return pos == pattern.size();
    }
};
