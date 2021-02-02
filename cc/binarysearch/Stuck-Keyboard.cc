// O(N) time | O(1) space
bool solve(string typed, string target) {
    int j = 0, i = 0;
    while(i < target.size()) {
        if(j == typed.size())
            return false;
        if(target[i] == typed[j]){
            j++;
            i++;
        }
        else{
            if(j && typed[j] == typed[j-1])
                j++;
            else return false;
        }
    }
    while(j < typed.size() && typed[j] == typed[j-1]) j++;
    return j == typed.size();
}
