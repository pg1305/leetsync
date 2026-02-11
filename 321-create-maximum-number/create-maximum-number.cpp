class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;
        for (int num : nums) {
            while (!st.empty() && drop > 0 && st.back() < num) {
                st.pop_back();
                drop--;
            }
            st.push_back(num);
        }
        st.resize(k);
        return st;
    }
    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> res;
        while (!a.empty() || !b.empty()) {
            if (a > b) {
                res.push_back(a[0]);
                a.erase(a.begin());
            } else {
                res.push_back(b[0]);
                b.erase(b.begin());
            }
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;
        int m = nums1.size(), n = nums2.size();
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> part1 = maxSubsequence(nums1, i);
            vector<int> part2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(part1, part2);
            best = max(best, candidate);
        }
        return best;
    }
};
