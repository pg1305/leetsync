class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rowS(m, vector<int>(n + 1, 0));
        vector<vector<int>> colS(m + 1, vector<int>(n, 0));
        vector<vector<int>> diagS(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> antiS(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowS[i][j + 1] = rowS[i][j] + grid[i][j];
                colS[i + 1][j] = colS[i][j] + grid[i][j];
                diagS[i + 1][j + 1] = diagS[i][j] + grid[i][j];
                antiS[i + 1][j] = antiS[i][j + 1] + grid[i][j];
            }
        }
        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int target = rowS[i][j + k] - rowS[i][j];
                    bool ok = true;
                    for (int r = i; r < i + k && ok; r++) {
                        if (rowS[r][j + k] - rowS[r][j] != target) ok = false;//ROW SUM
                    }
                    for (int c = j; c < j + k && ok; c++) {
                        if (colS[i + k][c] - colS[i][c] != target) ok = false;//COL SUM
                    }
                    int d1 = diagS[i + k][j + k] - diagS[i][j];
                    int d2 = antiS[i + k][j] - antiS[i][j + k];
                    if (d1 != target || d2 != target) ok = false;//BOTH DIAGS
                    if (ok) return k;
                }
            }
        }
        return 1;
    }
};