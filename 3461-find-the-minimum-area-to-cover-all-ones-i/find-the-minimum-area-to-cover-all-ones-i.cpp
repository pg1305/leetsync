using VVI = vector<vector<int>>;
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int left = n, right = 0;
        int top = 0, bottom = m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                left = min(left, i);
                right = max(right, i);
                top = max(top, j);
                bottom = min(bottom, j);}
            }
        }
        return (right - left + 1)*(top - bottom + 1); 
    }
};