class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxD = 0;
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int diag = dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1];
            int area = dimensions[i][0]*dimensions[i][1];
            if(diag > maxD || diag == maxD && area > maxArea){
                maxD = diag;
                maxArea = area;
            }
        }
        return maxArea;
    }
};