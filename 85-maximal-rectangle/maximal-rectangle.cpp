class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> height(cols, 0), left(cols, 0), right(cols, cols);

        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            int curr_left = 0, curr_right = cols;

            // 1. Update height
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], curr_left);
                else {
                    left[j] = 0;
                    curr_left = j + 1;
                }
            }
            for (int j = cols - 1; j >= 0; --j) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], curr_right);
                else {
                    right[j] = cols;
                    curr_right = j;
                }
            }
            for (int j = 0; j < cols; ++j) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }
        return maxArea;
    }
};