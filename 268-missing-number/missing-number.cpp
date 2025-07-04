class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // for (int i = 0; i <= n; ++i) {
        //     bool found = false;
        //     for (int j = 0; j < n; ++j) {
        //         if (nums[j] == i) {
        //             found = true;
        //             break;
        //         }
        //     }
        //     if (!found) return i;
        // }
        // return 0;
        int n = nums.size();
        int expect = n*(n+1)/2;
        int actual = accumulate(nums.begin(),nums.end(),0);
        return expect - actual;
    }
};
