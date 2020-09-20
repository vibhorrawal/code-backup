O(n) time | O(n) space
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        string dot = ".", cd = "..", token;
        stringstream ss(path);
        while(getline(ss, token, '/')){
            if(token == dot || token == "")
                continue;
            if(token == cd && !dq.empty())
                dq.pop_back();
            if(token != cd)
                dq.push_back(token);
        }
        string res = "";
        while(!dq.empty()){
            res += '/' + dq.front() ;
            dq.pop_front();
        }
        return res.size() ? res: "/";
    }
};