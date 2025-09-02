class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];  
            return a[0] < b[0];                   
        });

        for (int i = 0; i < n; i++) {
            int y_i = points[i][1];
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int y_j = points[j][1];
                if (y_j <= y_i && y_j > maxY) {
                    ans++;
                    maxY = y_j; 
                }
            }
        }

        return ans;
    }
};
