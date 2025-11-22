class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for(int c : nums){
            ans += (c - m);
        }
        return ans;
    }
};