class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for(int i = n - 1; i >=0; i--){
            long long pts = questions[i][0];
            long long bp = questions[i][1];
            long long nxt = i + bp + 1;
            long long take = pts + (nxt < n ? dp[nxt] : 0);
            long long skip = dp[i + 1];
            dp[i] = take > skip ? take : skip;
        }
        return dp[0];
    }
};