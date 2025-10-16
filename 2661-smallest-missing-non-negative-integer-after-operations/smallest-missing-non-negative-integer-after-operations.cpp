class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> rem(value, 0);
        for (int num : nums) {
            int r = ((num % value) + value) % value; 
            rem[r]++;
        }
        int res = 0;
        while (true) {
            int r = res % value;
            if (rem[r] == 0) break;
            rem[r]--;
            res++;
        }
        return res;
    }
};
