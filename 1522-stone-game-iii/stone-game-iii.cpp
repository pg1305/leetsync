class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1);
        for(int i = n - 1; i >= 0; i--){
            int bs = INT_MIN;
            int sum = 0;
            for(int k = 1; k <= 3; k++){
                if(i + k > n) break;
                sum += stoneValue[i + k - 1];
                bs = max(bs, sum - dp[i + k]);
            }
            dp[i] = bs;
        }
        if(dp[0] > 0) return "Alice";
        else if(dp[0] < 0) return "Bob";
        else return "Tie";
    }
};