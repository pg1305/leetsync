class Solution {
    //wal == 1, guard == 2, guarded cell == 3
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto &w : walls) grid[w[0]][w[1]] = 1; 
        for (auto &g : guards) grid[g[0]][g[1]] = 2; 
        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for (auto &g : guards) {
            for (auto [dx, dy] : dirs) {
                int x = g[0] + dx, y = g[1] + dy;
                while (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 1 || grid[x][y] == 2) break;
                    if (grid[x][y] == 0) grid[x][y] = 3; 
                    x += dx;
                    y += dy;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    count++;
        
        return count;   
    }
};