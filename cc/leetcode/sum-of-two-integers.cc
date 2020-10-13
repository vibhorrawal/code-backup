// first we just add without carry, and then find carry(for all bits), and then add these
class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) return a;
        int sum = a ^ b;
        int carry = (unsigned int)(a & b) << 1; // as a can be -1, we have to use unsigned
        return getSum(sum, carry);
    }
}; // O(log(n)) time
