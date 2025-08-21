class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
       int m = mat.size();
       int n = mat[0].size();
       vector<int> h(n, 0);
       int cnt = 0;
       for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            h[j] = mat[i][j] == 1 ? h[j] + 1 : 0;
        }
        for(int j = 0; j < n; j++){
            int mini = h[j];
            for(int k = j; k >= 0 && mini > 0; k--){
                mini = min(mini, h[k]);
                cnt += mini;
            }
        }
       }
       return cnt;
    }
};