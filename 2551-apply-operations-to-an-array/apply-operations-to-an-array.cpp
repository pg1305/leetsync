class Solution {
public:
    int countFreq(vector<int> &nums){
        int count  = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) count++;
        }
        return count;
    }
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        vector<int> result (n,0);
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                result[idx++] = nums[i];
            }
        }
        return result;

    }
};