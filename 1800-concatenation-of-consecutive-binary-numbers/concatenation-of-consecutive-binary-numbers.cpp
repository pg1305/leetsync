class Solution {
    const int mod = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        int bits = 0;
        for(int i = 1; i <= n; i++){
            if((i & (i - 1)) == 0) bits++;
            res = ((res << bits) | i) % mod;
        }
        return res;
    }
};