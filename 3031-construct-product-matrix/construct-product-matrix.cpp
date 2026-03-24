class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345;
        vector<vector<int>> p(grid.size(), vector<int>(grid[0].size()));
        long long pref = 1, suff = 1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                p[i][j] = pref;
                pref = (pref * grid[i][j]) % mod;
            }
        }
        for(int i = grid.size() - 1; i >= 0; i--){
            for(int j = grid[0].size() - 1; j >= 0; j--){
                p[i][j] = (p[i][j] * suff)% mod;
                suff = (suff * grid[i][j])%mod;
            }
        }
        return p;
    }
};