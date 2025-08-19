class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, str = 0;
        for(int num : nums){
            str = (num == 0) ? str + 1 : 0;
            cnt += str;
        }
        return cnt;
    }
};