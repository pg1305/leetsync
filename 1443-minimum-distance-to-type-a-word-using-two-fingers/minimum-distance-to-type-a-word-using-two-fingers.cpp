class Solution {
    int dist(int a, int b){
        return abs(a/6 - b/6) + abs(a % 6 - b % 6);
    }
public:
    int minimumDistance(string word) {
        vector<int> dp(26, 0);
        int mx = 0, sm = 0;
        for(int i = 0; i < word.length() - 1; i++){
            int p = word[i] - 65;
            int c = word[i + 1] - 65;
            int d = dist(p, c);
            sm += d;
            int curr = 0;
            for(int j = 0; j < 26; j++) curr = max(curr, dp[j] + d - dist(j, c));
            dp[p] = max(dp[p], curr);
            mx = max(mx, dp[p]);
        }
        return sm - mx;
    }
};