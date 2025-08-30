class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b){
            return b[0] - b[1] < a[0] - a[1];
        });
        int ans = 0;
        int n = costs.size();
        for(int i = 0; i < n; i++){
            if(i < n/2){
                ans+=costs[i][1];
            }else{
                ans+=costs[i][0];
            }
        }
        return ans;
    }
};