class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minId = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxId = max_element(nums.begin(), nums.end()) - nums.begin();
        int l = min(minId, maxId);
        int r = max(minId, maxId);
        return min({r + 1, n - l, l + 1 + n - r});
    }
};