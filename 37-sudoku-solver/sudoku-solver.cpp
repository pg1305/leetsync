
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) return false;
        }
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == num) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {  
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValidSudoku(board, i, j, num)) {
                            board[i][j] = num;  // Place the number

                            if (solve(board)) return true; // If solved, return true

                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // If no valid number is found, return false
                }
            }
        }
        return true; // If all cells are filled, return true
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // Start solving
    }
};

