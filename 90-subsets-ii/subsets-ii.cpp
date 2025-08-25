class Solution {
    void subsetswithDupHelper(int i, vector<int> &nums, vector<int> &subset, vector<vector<int>> &res){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        subsetswithDupHelper(i + 1, nums, subset, res);
        subset.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        subsetswithDupHelper(i + 1, nums, subset, res);     
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> subset;
        sort(nums.begin(), nums.end());
        subsetswithDupHelper(0, nums, subset, res);
        return res;
    }
};