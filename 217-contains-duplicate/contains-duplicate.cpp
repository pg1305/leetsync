class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n - 1;
        for(int k = 1; k < n ; k++){
            if (nums[k]==nums[k-1]) return true;
        }
        return false;
    }
};