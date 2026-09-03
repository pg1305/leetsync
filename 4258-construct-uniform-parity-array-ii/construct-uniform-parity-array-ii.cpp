class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int min_odd = 1e9 + 7;
        for (int i : nums1) if (i & 1) min_odd = min(min_odd, i);
        
        auto helper = [&](int target_p) {
            for (int i : nums1) {
                if (i % 2 != target_p && i <= min_odd) return false;
            }
            return true;
        };
        return helper(0) || helper(1);
    }
};