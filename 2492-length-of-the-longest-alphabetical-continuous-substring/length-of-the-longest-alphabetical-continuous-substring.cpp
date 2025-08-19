class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int maxS = 1;
        int str = 1;
        for(int i = 0; i < n - 1; i++){
            if(s[i+1] - s[i] == 1){
                str++;
                maxS = max(maxS, str);
            }else{
                str = 1;
            }
        }
        return maxS;
    }
};