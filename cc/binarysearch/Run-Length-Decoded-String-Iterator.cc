class RunLengthDecodedIterator {
    public:
    vector<char> st;
    vector<int>count;
    int i = 0;
    RunLengthDecodedIterator(string s) {
        int i = 0, n = 0;
        while(i < s.size()){
            if(islower(s[i])){
                count.push_back(n);
                st.push_back(s[i]);
                n = 0;
            }
            else{
                n = (n * 10) + s[i] - '0';
            }
            i++;
        }
    }

    string next() {
        count[i]--;
        char c = st[i];
        if(count[i] == 0) i++;
        return string(1,c);
    }

    bool hasnext() {
        return i != st.size();
    }
};
