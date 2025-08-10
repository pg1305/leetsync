class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        int n = size(nums);
        for(int i = 0; i < n; i++){
            int x = abs(nums[i]);
            if(nums[x-1] < 0){
                result.push_back(x);
            }
            nums[x-1] = -nums[x-1]; 
        }
        return result;
    }
};