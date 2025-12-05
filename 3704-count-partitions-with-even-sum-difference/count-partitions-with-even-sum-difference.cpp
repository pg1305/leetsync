class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count = 0;
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            sum += nums[i];
            if ((2 * sum - tot) % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};
