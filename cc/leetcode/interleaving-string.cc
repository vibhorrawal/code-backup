// O(mn) time and space
class Solution {
    string a1,a2,a3;
    map<pair<int, pair<int,int>>, bool> memo;
    bool util(int i, int j, int k){
        if(memo.find({i,{j,k}}) != memo.end())
            return memo[{i,{j,k}}];
        
        if(k == a3.size() && i == a1.size() && j == a2.size())
            return memo[{i,{j,k}}] = true;
        if(i == a1.size()){
            if(a2[j] == a3[k])
                return util(i,j+1,k+1);
            else
                return memo[{i,{j,k}}] = false;
        }
        if(j == a2.size()){
            if(a1[i] == a3[k])
                return util(i+1,j,k+1);
            else
                return memo[{i,{j,k}}] = false;
        }
        if(a1[i] == a2[j]){
            if(a3[k] != a1[i])
                return memo[{i,{j,k}}] = false;
            else 
                return memo[{i,{j,k}}] = util(i+1,j,k+1) || util(i,j+1,k+1);
        }
        if(a1[i] == a3[k])
            return util(i+1,j,k+1);
        if(a2[j] == a3[k])
            return util(i,j+1,k+1);
        return memo[{i,{j,k}}] = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        memo.clear();
        a1 = s1;
        a2 = s2;
        a3 = s3;
        return util(0,0,0);
    }
};
