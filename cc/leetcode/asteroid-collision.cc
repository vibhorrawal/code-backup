// O(n) space | O(n) time
class Solution {
public:
    inline bool fine(int a, int b){
        if((a >= 0 && b >= 0) || (a <= 0 && b <= 0) || (a <= 0 && b >= 0)) return true;
        else return false;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i : asteroids){
            if(st.empty() || fine(st.top(), i)) st.push(i);
            else{
                while(st.size() && !fine(st.top(), i) && i != 1e6){
                    if(st.top() == -i){
                            st.pop();
                            i = 1e6;
                            break;
                        }
                        else if(abs(st.top()) > abs(i)) {
                            i = 1e6;
                            break;
                        }
                        else st.pop();
                    }
                    if(i != 1e6) st.push(i);
            }
        }
        vector<int> res;
        while(st.size()){
            res.push_back(st.top()); st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
