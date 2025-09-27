class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
    if (nums.size() < 3) {
        return 0;
    }
    sort(nums.begin(), nums.end()); // Step 1
    for (int i = nums.size() - 1; i >= 2; --i) { // Step 2
        if (nums[i - 2] + nums[i - 1] > nums[i]) { // Step 3
            return nums[i - 2] + nums[i - 1] + nums[i]; // Step 4
        }
    }
    return 0;
}
};