class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> count; 
        
        for (int i = 0; i < secret.size(); ++i) {
            char s = secret[i];
            char g = guess[i];
            
            if (s == g) {
                bulls++;
            } else {
                if (count[s] < 0) cows++;  
                if (count[g] > 0) cows++;  
                
                count[s]++;  
                count[g]--;  
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
