class ProductOfNumbers {
    const int MAX = 40000;
    map<pair<int,int>,int> mp;
    vector<int> prod;
    int pos = -1;
public:
    ProductOfNumbers() {
        prod.resize(MAX);
    }

    void add(int num) {
        prod[++pos] = num;
    }

    int getProduct(int k) {
        if(mp.count({pos,k}))
            return mp[{pos,k}];
        int res = 1;
        for(int i = 0; i < k; i++){
            res *= prod[pos-i];
        }
        return mp[{pos,k}] = res;
    }
};
