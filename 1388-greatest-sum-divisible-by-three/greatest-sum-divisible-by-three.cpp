class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 3 == 0) return sum;

        int mod1a = 1e9, mod1b = 1e9; 
        int mod2a = 1e9, mod2b = 1e9; 

        for (int x : nums) {
            if (x % 3 == 1) {
                if (x < mod1a) { mod1b = mod1a; mod1a = x; }
                else if (x < mod1b) mod1b = x;
            } 
            else if (x % 3 == 2) {
                if (x < mod2a) { mod2b = mod2a; mod2a = x; }
                else if (x < mod2b) mod2b = x;
            }
        }

        if (sum % 3 == 1) {
            return max(sum - mod1a, sum - (mod2a + mod2b));
        } 
        else { 
            return max(sum - mod2a, sum - (mod1a + mod1b));
        }
    }
};
