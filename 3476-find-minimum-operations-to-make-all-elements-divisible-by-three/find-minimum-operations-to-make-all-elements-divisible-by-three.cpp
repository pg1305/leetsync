class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int c:nums){
            if(c % 3 != 0) count++;
        }
        return count;
    }
};