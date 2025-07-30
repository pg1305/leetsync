class Solution {
    
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this -> nums.swap(nums);
    }
    
    int pick(int target) {
        int count = 0;
        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                count++;
                if(rand() % count == 0){
                    idx = i;
                }
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */