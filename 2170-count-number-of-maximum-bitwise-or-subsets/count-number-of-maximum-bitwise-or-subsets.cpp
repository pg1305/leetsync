class Solution {
        int countSubsets(vector<int> &nums, int index, int curr, int count){
        if(index == nums.size()) return (curr == count) ? 1 : 0;
        int countWithout = countSubsets(nums, index + 1, curr, count);
        int countWith = countSubsets(nums, index + 1, curr | nums[index], count);
        return countWith + countWithout;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int count = 0;
        for(int num : nums){
            count |= num;
        }
        return countSubsets(nums, 0, 0, count);
    }

};