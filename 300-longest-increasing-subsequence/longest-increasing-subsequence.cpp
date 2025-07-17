class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // if(n == 0) return 0;
        // vector<int> dp(n,1);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //         if(nums[i] > nums[j]){
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(), dp.end());
        int n = nums.size();
        vector<int> dp;
        for(int num : nums){
            auto it = lower_bound(dp.begin(),dp.end(), num);
            if(it == dp.end()) dp.push_back(num);
            else *it = num;
        }
        return dp.size();
    }
};