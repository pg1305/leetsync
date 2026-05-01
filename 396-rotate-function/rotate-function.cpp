class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0;
        int tot = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); i++) f += i*nums[i];
        int res = f;
        for(int i = nums.size() - 1; i > 0; i--){
            f += tot - nums.size()*nums[i];
            res = max(res, f);
        }
        return res;
    }
};