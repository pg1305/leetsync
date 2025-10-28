class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum(n);
        prefix_sum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                if(prefix_sum[i] == prefix_sum[n-1]-prefix_sum[i]) 
                    ans+=2;
                else if(abs(prefix_sum[i]-prefix_sum[n-1]+prefix_sum[i]) == 1)
                    ans++;
            }
        }
        return ans;
    }
};