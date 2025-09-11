class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <  n - 1 && nums[l] <= nums[l + 1]) l++; // LEFTMOST
        if(l == n - 1) return 0;
        while (r > 0 && nums[r] >= nums[r - 1]) r--; //RIGHTMOST
        int subMin = *min_element(nums.begin() + l, nums.begin() + r + 1);
        int subMax = *max_element(nums.begin() + l, nums.begin() + r + 1);
        while(l > 0 && nums[l - 1] > subMin) l--;
        while(r < n - 1 && nums[r + 1] < subMax) r++;
        return r - l + 1;
    }
};