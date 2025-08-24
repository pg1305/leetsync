class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0;
        int longestW = 0;
        int start = 0;
        for(int i = 0; i < nums.size(); i++){
            zero += (nums[i] == 0);
            while(zero > 1){
                zero -= (nums[start] == 0);
                start++;
            }
            longestW = max(longestW, i - start);
        }
        return longestW;
    }
};