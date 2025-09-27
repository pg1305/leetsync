class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double area = 0;
        int n = p.size();
        double a = 0, b = 0, c = 0; 
        double semi = 0;
        for(int i =0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    area = max(area, abs( (p[j][0]-p[i][0]) * (p[k][1]-p[i][1]) - (p[j][1] - p[i][1]) * (p[k][0] - p[i][0]) ) * 0.5);       
                }
            }
        }
        return area;
    }
};