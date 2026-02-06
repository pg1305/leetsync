class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = n, r = 0;
        for(int l = 0; l < n; ++l){
            while(r < n && nums[r] <= 1LL*nums[l]*k) ++r;
            res = min(res, n - (r - l));
        }
        return res;
    }
};