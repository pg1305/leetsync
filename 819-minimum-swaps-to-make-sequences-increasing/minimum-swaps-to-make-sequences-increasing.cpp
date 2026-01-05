class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        vector<int> keep(n, INT_MAX);
        vector<int> swp(n, INT_MAX);
        
        keep[0] = 0;
        swp[0] = 1;
        
        for (int i = 1; i < n; i++) {
            // check normally
            if (nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) {
                keep[i] = keep[i-1];
                swp[i] = swp[i-1] + 1;
            }
            // check for cross order
            if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
                keep[i] = min(keep[i], swp[i-1]);
                swp[i] = min(swp[i], keep[i-1] + 1);
            }
        }
        
        return min(keep[n-1], swp[n-1]);
    }
};
