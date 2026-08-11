class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] + 1 == nums[i]){
                sum = sum + nums[i];
            }
            else {
                break;
            }
        }
        
        sort(nums.begin(), nums.end());
        
        while(true){
            bool found = false;
            for(int i = nums.size() - 1; i >= 0; i--){
                if(sum == nums[i]){
                    sum = sum + 1;
                    found = true;
                    break; 
                }
            }
            
            if (!found) {
                return sum;
            }
        }
    }
};