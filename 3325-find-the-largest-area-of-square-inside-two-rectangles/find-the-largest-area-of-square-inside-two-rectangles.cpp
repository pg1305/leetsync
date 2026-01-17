class Solution {
    using LL = long long;
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int sd = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int b = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                int h = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                sd = max(sd, min(b, h));
            }
        }
        return 1LL*sd*sd;
    }
};