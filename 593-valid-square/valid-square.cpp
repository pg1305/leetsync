class Solution {
    int distSq(vector<int> &A, vector<int> &B) {
        return (B[0] - A[0]) * (B[0] - A[0]) + (B[1] - A[1]) * (B[1] - A[1]);
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};

        // Sort to normalize the order of points
        sort(points.begin(), points.end());

        // After sorting, points[0] should be the bottom-left and points[3] top-right (roughly)
        int d01 = distSq(points[0], points[1]);
        int d02 = distSq(points[0], points[2]);
        int d03 = distSq(points[0], points[3]);

        // Check that all sides and diagonals are valid and not zero
        return d01 > 0 && d01 == distSq(points[1], points[3]) &&
               d02 == distSq(points[2], points[3]) &&
               d02 == d01 &&
               distSq(points[1], points[2]) == distSq(points[0], points[3]);
    }
};
