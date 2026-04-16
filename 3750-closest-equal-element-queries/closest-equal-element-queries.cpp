class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        vector<int> res;
        for(int i = 0;i < n; i++){
            mp[nums[i]].push_back(i);
        }
        for(int q: queries){
            vector<int>& vec = mp[nums[q]];
            if(vec.size() == 1){
                res.push_back(-1);
                continue;
            }
            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
            int sol = INT_MAX;
            int left = vec[(pos - 1 + vec.size()) % vec.size()];
            int d1 = abs(q- left);
            sol = min(sol, min(d1, n - d1));
            int right = vec[(pos + 1)%vec.size()];
            int d2 = abs(q - right);
            sol = min(sol, min(d2, n - d2));
            res.push_back(sol);
        }
        return res;
    }
};