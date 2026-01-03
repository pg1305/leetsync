class Solution {
    const int MOD = 1000000007;
    using LL = long long;
public:
    int numOfWays(int n) {
        LL x = 6, y = 6;// x -> alternative; y -> different
        for(int i = 2; i <= n; i++){
            LL newX = (3*x + 2*y) % MOD;
            LL newY = (2*x + 2*y) % MOD;
            x = newX;
            y = newY;
        }
        return (x + y) % MOD;
    }
};