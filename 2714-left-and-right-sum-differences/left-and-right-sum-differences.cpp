class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0;
        for(int i = 0; i < n; ++i){
            res[i] = left;
            left += nums[i];
        }
        int right = 0;
        for(int i = n - 1; i >= 0; --i){
            res[i] = abs(res[i] - right);
            right += nums[i];
        }
        return res;
    }
};