class Solution {
    int distSq(vector<int>& point1, vector<int>& point2){
        return pow(point2[1] - point1[1], 2) + pow(point2[0] - point1[0], 2);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int cnt = 0;
        
        int n = points.size();
        for(int i = 0; i < n; i++){
            unordered_map<int, int> mp;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                int dist = distSq(points[i], points[j]);
                mp[dist]++;
            }
            for(auto & [dist, count] : mp) cnt += count*(count - 1);
        }
        return cnt;
    }
};