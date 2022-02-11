// all O(1) calls
class PeekableIterator {
    vector<int> v;
    int i;
    public:
    PeekableIterator(vector<int>& nums) {
        v = nums;
        i = -1;
    }

    int peek() {
        return v[i+1];
    }

    int next() {
        return v[++i];
    }

    bool hasnext() {
        return i + 1 < v.size();
    }
};