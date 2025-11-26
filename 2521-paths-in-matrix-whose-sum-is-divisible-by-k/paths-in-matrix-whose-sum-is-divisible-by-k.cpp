class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1000000007;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        int rem0 = grid[0][0] % k;
        dp[0][0][rem0] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue; 
                
                int val = grid[i][j];
                for (int r = 0; r < k; ++r) {
                    long long ways = 0;
                    
                    // From top
                    if (i > 0) {
                        ways += dp[i - 1][j][r];
                    }
                    // From left
                    if (j > 0) {
                        ways += dp[i][j - 1][r];
                    }
                    
                    if (ways == 0) continue;
                    
                    int newRem = (r + val) % k;
                    dp[i][j][newRem] = (dp[i][j][newRem] + ways) % MOD;
                }
            }
        }
        
        return dp[m - 1][n - 1][0];
    }
};
