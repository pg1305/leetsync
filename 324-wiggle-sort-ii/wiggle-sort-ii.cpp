class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = (n + 1)/2;
        int l = mid - 1;
        int r = n - 1;
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                nums[i]=sorted[l--];
            }else{
                nums[i]=sorted[r--];
            }
        }     
    }
};