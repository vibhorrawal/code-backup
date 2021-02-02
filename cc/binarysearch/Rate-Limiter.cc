class RateLimiter {
    unordered_map<int,int> mp;
    int expire;
    public:
    RateLimiter(int expire) {
        this->expire = expire;
    }

    bool limit(int uid, int timestamp) {
        int is_prev = mp.count(uid), prev = mp[uid];
        if(is_prev){
            if(timestamp - prev < expire){
                return true;
            }
            else {
                mp[uid] = timestamp;
                return false;
            }
        }
        mp[uid] = timestamp;
        return false;
    }
};
