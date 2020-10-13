class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
        string rev = b.to_string();
        reverse(rev.begin(), rev.end());
        bitset<32> rb(rev);
        return (uint32_t) rb.to_ulong();
    }
};
