#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        // max length of n in base 2 minus 1
        int max_m = (int)(log2(num));

        for (int m = max_m; m >= 1; --m) {
            long long left = 2, right = pow(num, 1.0/m) + 1;
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                long long s = 1, cur = 1;
                // Compute sum of geometric series s = 1 + mid + mid^2 + ... + mid^m
                for (int i = 0; i < m; ++i) {
                    if (s > num) break; // prevent overflow
                    cur *= mid;
                    s += cur;
                }
                if (s == num)
                    return to_string(mid);
                if (s < num)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return to_string(num - 1);
    }
};