class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int left = 0, sum = 0, max_sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            sum += nums[right];
            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
};
