// O(mn) time | O(mn) space
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int> (n, 1));
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                paths[i][j] = paths[i][j-1] + paths[i-1][j];
        
        return paths[m-1][n-1];
    }
};

// O(mn) time | O(m) space
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> p1(m, 1), p2(m,1), temp;

        for(int i = 1; i < n; i++){
           for(int j = 1; j < m; j++){
               p1[j] = p1[j-1] + p2[j]; 
            } 
            temp = p1;
            p1 = p2;
            p2 = temp;
        }
        return p2[m-1];
    }
};

// O(m+n) time | O(1) space  **avoid as it can overflow
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n)
            swap(m,n);
        long long res = 1;
        for(int i = n; i <= m + n - 2; i++)
            res *= i;
        
        for(int i = 2; i <= m - 1; i++)
            res /= i;
        
        return res;
    }
};