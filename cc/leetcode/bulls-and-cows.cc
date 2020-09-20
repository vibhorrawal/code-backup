class Solution {
public:
    string getHint(string secret, string guess) {
        int counts[10], countg[10];
        bool used[10];
        int countA = 0, countB = 0;
        for(int i = 0; i < 10; i++){
            counts[i] = 0;
            countg[i] = 0;
            used[i] = false;
        }
        for(auto c: secret){
            counts[c - '0']++;
        }
        for(auto c: guess){
            countg[c - '0']++;
        }
        
        for(int i = 0; i < min(secret.size(), guess.size()); i++){
            if(secret[i] == guess[i]){
                int c = secret[i] - '0';
                counts[c]--;
                countg[c]--;
                countA++;
                used[c] = true;
            }
        }
        for(int i = 0; i < 10; i++){
            countB += min(counts[i], countg[i]);
        }
        return to_string(countA) + A + to_string(countB) + B;
    }
};
