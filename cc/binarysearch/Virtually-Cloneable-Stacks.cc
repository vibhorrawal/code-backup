class VirtuallyCloneableStacks {
    vector<int> v;
    int id;
    public:
    VirtuallyCloneableStacks() {
        v = {0};
        id = 0;
    }

    void copyPush(int i) {
        v.push_back(v[i] + 1);
    }

    void copyPop(int i) {
        v.push_back(v[i] - 1);
    }

    int size(int i) {
        return v[i];
    }
};

// both copy -> amortized O(1)
// size -> O(1)