class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), cost = 0;
        for(int i = 1; i < n; i++){
            int maxC = 0;
            while (i < n and colors[i] == colors[i - 1]) {
                cost += neededTime[i - 1];
                maxC = max(maxC, neededTime[i - 1]);
                ++i;
            }
            cost += neededTime[i - 1];
            maxC = max(maxC, neededTime[i - 1]);
            if(maxC != 0) cost -= maxC;
        }
        return cost;
    }
};