class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> frq;
        frq.reserve(n);
        for(int l = 0, r = 0; r < n; r++){
            int x = nums[r];
            auto it = frq.find(x);
            int &f = (it == frq.end()) ? frq[x] = 1: ++(it -> second);
            while(f > k) frq[nums[l++]]--;
            cnt = max(cnt, r - l + 1);
        }
        return cnt;
    }
};