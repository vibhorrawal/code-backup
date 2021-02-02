// O(n ^ 2) time | O(1) space
bool solve(string s) {
    string bs = "binarysearch";
    vector<int> id;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == 'b') id.push_back(i);

    for(int j = 1; j <= s.size(); j++){
        for(int i : id){
            int b = 0;
            while(i < s.size() && b < bs.size() &&
            s[i] == bs[b]){
                i += j;
                b++;
            }
            // cout<<b<<' ';
            if(b == bs.size())
                return true;
        }
    }
    return false;
}
