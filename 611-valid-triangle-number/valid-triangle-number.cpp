class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i < n - 2; i++){
            if(nums[i] == 0) continue; // zero can't be a triangle side
            int k = i + 2;
            for(int j = i + 1; j < n - 1; j++){
                while(k < n && nums[i] + nums[j] > nums[k]){
                    k++;
                }
                count += k - j - 1; // ✅ Count valid third sides
            }
        }
        return count;
    }
};
