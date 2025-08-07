class Solution {
public:
typedef unsigned long long ull;
    string smallestGoodBase(string n_str) {
    ull n = stoull(n_str);
    
    for (int m = (int)(log2(n)); m >= 1; --m) {
        ull left = 2, right = pow(n, 1.0 / m) + 1;

        while (left <= right) {
            ull k = left + (right - left) / 2;
            ull sum = 1, curr = 1;

            for (int i = 1; i <= m; ++i) {
                curr *= k;
                sum += curr;
                if (sum > n) break;
            }

            if (sum == n)
                return to_string(k);
            else if (sum < n)
                left = k + 1;
            else
                right = k - 1;
        }
    }

    // Fallback: base n-1 always works for 2 digits "11"
    return to_string(n - 1);
}

};