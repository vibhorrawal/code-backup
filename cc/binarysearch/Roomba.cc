#include "solution.hpp"
using namespace std;

class Solution {
    public:
    bool solve(vector<string>& moves, int x, int y) {
        int dx = 0, dy = 0;
        for (auto s : moves) {
            if (s == "NORTH") dy++;
            if (s == "SOUTH") dy--;
            if (s == "EAST") dx++;
            if (s == "WEST") dx--;
        }
        return x == dx && y == dy;
    }
};

bool solve(vector<string>& moves, int x, int y) {
    return (new Solution())->solve(moves, x, y);
}
