class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        vector<int> sumX(n);
        vector<int> sumY(n);
        for(int i = 0; i < m; i++){
            int rx = 0, ry = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'X') rx++;
                else if(grid[i][j] == 'Y') ry++;
                sumX[j] += rx;
                sumY[j] += ry;
                if(sumX[j] > 0 & sumX[j] == sumY[j]) cnt++; 
            }
        }
        return cnt;
    }
};