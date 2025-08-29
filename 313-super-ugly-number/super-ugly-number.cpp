class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;

        int k = primes.size();
        vector<int> primeIndices(k, 0);  
        vector<int> dp(n, 0);          
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            long minVal = LONG_MAX;
            for (int j = 0; j < k; j++) {
                minVal = min(minVal, (long)primes[j] * dp[primeIndices[j]]);
            }
            dp[i] = minVal;
            for (int j = 0; j < k; j++) {
                if ((long)primes[j] * dp[primeIndices[j]] == minVal) {
                    primeIndices[j]++;
                }
            }
        }
        return dp[n - 1];
    }
};
