class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; ++a) {
            long b = c - a * a;
            long sqrt_b = (long)sqrt(b);
            if (sqrt_b * sqrt_b == b) {
                return true;
            }
        }
        return false;
    }
};
