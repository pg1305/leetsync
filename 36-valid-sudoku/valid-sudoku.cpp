class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // vector<unordered_set<char>> rows(9),cols(9),sqrs(9);
        // for(int i=0;i<9;i++){
        //     for(int j=0;j<9;j++){
        //         char num=board[i][j];
        //         if(num=='.') continue;
        //         int boxInd=(i/3)*3+j/3;
        //         if(rows[i].count(num)||cols[j].count(num)||sqrs[boxInd].count(num)) return false;
        //         rows[i].insert(num);
        //         cols[j].insert(num);
        //         sqrs[boxInd].insert(num);
        //     }
        // }
        // return true;
        for(int i = 0; i < 9; i++){
            vector<bool> seen(9, false);
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if(seen[num]) return false;
                seen[num] = true;
            }
        }
        for(int j = 0; j < 9; j++){
            vector<bool> seen(9, false);
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if(seen[num]) return false;
                seen[num] = true;
            }
        }
        for(int br = 0; br < 3; br++){
            for(int bc = 0; bc < 3; bc++){
                vector<bool> seen(9, false);
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        int r = br*3 + i;
                        int c = bc*3 + j;
                        if(board[r][c] == '.') continue;
                        int num = board[r][c] - '1';
                        if(seen[num]) return false;
                        seen[num] = true;
                    }
                }
            }
        }
        return true;
    }
};