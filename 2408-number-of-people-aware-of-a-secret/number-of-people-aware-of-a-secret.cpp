class Solution {
    const long long MOD = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> knows(n + 1, 0);
        knows[1] = 1; 
        
        long long share = 0; 

        for (int day = 2; day <= n; day++) {
            if (day - delay >= 1) 
                share = (share + knows[day - delay]) % MOD;
            
            if (day - forget >= 1) 
                share = (share - knows[day - forget] + MOD) % MOD;

            knows[day] = share;
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + knows[i]) % MOD;
        }
        return ans;
    }
};
