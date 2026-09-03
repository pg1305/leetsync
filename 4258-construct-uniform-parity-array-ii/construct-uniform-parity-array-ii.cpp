class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min = *min_element(nums1.begin(), nums1.end());
        if(min % 2 == 1) return true;
        else{
            for(int num:nums1){
                if(num % 2 == 1) return false;
            }
        }
        return true;
    }
};