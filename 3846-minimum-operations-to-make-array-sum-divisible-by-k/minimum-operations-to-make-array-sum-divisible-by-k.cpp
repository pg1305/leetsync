class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int numSum, rez;

        for(auto num:nums){
            numSum += num;
        }
        rez = numSum % k;
        return rez;
    }
};