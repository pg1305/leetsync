class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            int X = points[i][0];
            int Y = points[i][1];
            int targetX = points[i + 1][0];
            int targetY = points[i + 1][1];
            res += max(abs(targetX - X), abs(targetY - Y));
        }
        return res;
    }
};