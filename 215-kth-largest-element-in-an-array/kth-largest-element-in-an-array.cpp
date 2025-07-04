class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        sort(nums.begin(),nums.end());
        return nums[n-k];
    }
};