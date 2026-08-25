class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int res = k;
        while(seen.count(res)) res+= k;
        return res;
    }
};