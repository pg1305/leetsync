class Solution {
public:
    bool isNonDecreasing(const vector<long long>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        vector<long long> arr(nums.begin(), nums.end());
        int ops = 0;
        while (!isNonDecreasing(arr)) {
            int n = arr.size();
            long long minSum = LLONG_MAX;
            int idx = -1;
            for (int i = 0; i < n - 1; i++) {
                long long s = arr[i] + arr[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }
            arr[idx] = arr[idx] + arr[idx + 1];
            arr.erase(arr.begin() + idx + 1);

            ops++;
        }
        return ops;
    }
};
