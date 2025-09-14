class Solution {
    long mod = 1e9 + 7;
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> count(n);
        for(auto &request : requests){
            count[request[0]]++;
            if(request[1] + 1 < n) count[request[1] + 1] --;
        }
        for(int i = 1; i < n; i++) count[i] += count[i-1];
        sort(count.begin(), count.end());
        sort(nums.begin(), nums.end());
        long res = 0;
        for(int i = 0; i < n; i++){
            res += (long)nums[i] * count[i];
        }
        return res % mod;
    }
};