class Solution {
public:
    long long getOperations(long long n) {
        long long res = 0;
        long long ops = 0;
        for (long long powerOfFour = 1; powerOfFour <= n; powerOfFour *= 4) {
            long long l = powerOfFour;
            long long r = min(n, powerOfFour * 4 - 1);
            ops++;
            res += (r - l + 1) * ops;
        }
        return res;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ans += (getOperations(r) - getOperations(l - 1) + 1) / 2;
        }
        return ans;
    }
};