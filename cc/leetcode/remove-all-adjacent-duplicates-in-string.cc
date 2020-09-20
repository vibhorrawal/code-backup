class Solution {
public:
string removeDuplicates(string s) {
int n = s.length();

    for(int i=1;i<n;){
        if(s[i] == s[i-1]){
            s.erase(i-1, 2);
            i=max(1,i-1);
        }
        else{
            i++;
        }
    }
    return s;
}

};
