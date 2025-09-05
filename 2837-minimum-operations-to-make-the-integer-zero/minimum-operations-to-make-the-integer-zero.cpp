class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long ops = 0; ops <= 60; ++ops) {
            long long target = 1LL * num1 - ops * 1LL * num2;

            // Need target >= ops (can split powers down to reach exactly ops terms).
            if (target < ops) {
                // If num2 >= 0, target only decreases as ops grows, so no point continuing.
                if (num2 >= 0) break;
                else continue;
            }

            // Manual popcount (Brian Kernighan).
            int ones = 0;
            unsigned long long x = static_cast<unsigned long long>(target); // target >= 0 here
            while (x) {
                x &= (x - 1);
                ++ones;
            }

            if (ones <= ops) return static_cast<int>(ops);
        }
        return -1;
    }
};
