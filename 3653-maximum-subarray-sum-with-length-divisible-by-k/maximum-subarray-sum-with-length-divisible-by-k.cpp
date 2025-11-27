class Solution {
    using LL = long long;
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        LL preS = 0, maxS = LONG_LONG_MIN;
        vector<LL> kSum(k, LONG_LONG_MAX/2);
        kSum[k - 1] = 0;
        for(int i = 0; i < n; i++){
            preS += nums[i];
            maxS = max(maxS, preS - kSum[i % k]);
            kSum[i % k] = min(kSum[i % k], preS);
        }
        return maxS;
    }
};