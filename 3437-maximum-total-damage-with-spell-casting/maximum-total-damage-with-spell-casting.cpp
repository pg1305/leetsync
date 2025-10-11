class Solution {
public:
using ll = long long;
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, ll> dmg;
        int mx = 0;
        for(int p : power){
            dmg[p] += p;
        }
        vector<int> vals;
        for(auto& [k, v]:dmg) vals.push_back(k);
         sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<ll> dp(n, 0);
        for (int i = 0; i < n; i++) {
            ll take = dmg[vals[i]];
            int j = upper_bound(vals.begin(), vals.end(), vals[i] - 3) - vals.begin() - 1;
            if (j >= 0) take += dp[j];
            ll skip = (i > 0) ? dp[i - 1] : 0;
            dp[i] = max(skip, take);
        }
        return dp.back();
    }
};