class Solution {
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxFreqSum(string s) {
        int maxV = 0, maxC = 0;
        unordered_map<char, int> freq;
        for(char c:s){
            freq[c]++;
        }
        for(char c = 'a'; c <= 'z'; c++){
            if(isVowel(c)) maxV = max(maxV, freq[c]);
            else maxC = max(maxC, freq[c]);
        }
        return maxV + maxC;
    }
};