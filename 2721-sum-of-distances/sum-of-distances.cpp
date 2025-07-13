class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);
        unordered_map<int, vector<int>> indices;

        // Step 1: collect all indices of each number
        for(int i = 0; i < n; i++) {
            indices[nums[i]].push_back(i);
        }

        for (auto& [val, idx_list] : indices) {
            int m = idx_list.size();
            vector<long long> prefix(m, 0);
            prefix[0] = idx_list[0];
            for(int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + idx_list[i];
            }

            for(int i = 0; i < m; i++) {
                long long left = (long long)i * idx_list[i] - (i > 0 ? prefix[i - 1] : 0);
                long long right = (prefix[m - 1] - prefix[i]) - (long long)(m - 1 - i) * idx_list[i];
                res[idx_list[i]] = left + right;
            }
        }

        return res;
    }
};
