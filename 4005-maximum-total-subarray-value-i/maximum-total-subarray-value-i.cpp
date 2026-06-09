class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX, maxi = INT_MIN;
        for(int num: nums){
            maxi = max(maxi, num);
            mini = min(mini, num);
        }
        return (long long)(maxi - mini)*k;
    }
};