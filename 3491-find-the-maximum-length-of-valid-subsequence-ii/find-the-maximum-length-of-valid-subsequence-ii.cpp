class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp(k,vector<int> (k,0));
        for(int i = 0; i < n; i++){
            int curRem = nums[i] % k;
            for(int prevRem = 0; prevRem < k; prevRem++){
                dp[curRem][prevRem] = max(dp[curRem][prevRem], 1 + dp[prevRem][curRem]);
                ans = max(ans,dp[curRem][prevRem]);
            }
        }
        return ans;
    }
};