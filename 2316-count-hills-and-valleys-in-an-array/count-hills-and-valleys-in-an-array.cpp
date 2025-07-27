#include<algorithm>
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        int count = 0;
        for(int i = 1 ; i < nums.size() - 1; i++){
            if((nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) || (nums[i] < nums[i + 1] && nums[i] < nums[i - 1])) count++;
        }
        return count;
    }
};