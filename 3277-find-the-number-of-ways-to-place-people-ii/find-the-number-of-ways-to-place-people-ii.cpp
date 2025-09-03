class Solution {

public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> vec;
        for (auto& p:points) {
            vec.push_back({p[0], -p[1]});
        }
        ranges::sort(vec);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int yi = -vec[i].second;
            int maxyj = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int yj = -vec[j].second;
                if (yj <= yi && yj > maxyj) {
                    maxyj = yj;
                    ans++;
                }
            }
        }
        return ans;
    }
};