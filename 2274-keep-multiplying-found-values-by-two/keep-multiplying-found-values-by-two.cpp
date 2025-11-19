class Solution {
    bool found(vector<int> &nums, int num){
        for(int i : nums){
            if(i == num) return true;
        }
        return false;
    }
public:
    int findFinalValue(vector<int>& nums, int original) {
        while(found(nums, original)) {
            original *= 2;
        }
        return original;
    }
};
