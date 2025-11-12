class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int hcf = 0;
        for(int num:nums){
            if(num == 1) ones++;
            hcf = __gcd(hcf, num);
        }
        if(ones > 0) return n - ones;
        if(hcf > 1) return -1;
        int minL = n;
        for(int i = 0; i < n; i++){
            int hcf = 0;
            for(int j = i; j < n; j++){
                hcf = __gcd(hcf, nums[j]);
                if(hcf == 1){
                    minL = min(minL, j - i + 1);
                    break;
                }
            }
        }
        return minL + n - 2;
    }
};