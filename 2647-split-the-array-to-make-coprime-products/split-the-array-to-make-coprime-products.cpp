#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to factorize a number into unique prime factors
    vector<int> getFactors(int x) {
        vector<int> factors;
        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                factors.push_back(d);
                while (x % d == 0) x /= d;
            }
        }
        if (x > 1) factors.push_back(x);
        return factors;
    }

    int findValidSplit(vector<int>& nums) {
        int n = nums.size();

        // Step 1: factorize all numbers
        vector<vector<int>> factorsList(n);
        unordered_map<int, int> right;
        for (int i = 0; i < n; i++) {
            factorsList[i] = getFactors(nums[i]);
            for (int f : factorsList[i]) {
                right[f]++;  // count prime frequency
            }
        }

        unordered_map<int, int> left;

        // Step 2: sweep from left to right
        for (int i = 0; i < n - 1; i++) {
            for (int f : factorsList[i]) {
                left[f]++;
                right[f]--;
                if (right[f] == 0) right.erase(f);
            }

            // Step 3: check if disjoint
            bool ok = true;
            for (auto &p : left) {
                if (right.count(p.first)) {
                    ok = false;
                    break;
                }
            }

            if (ok) return i;
        }

        return -1;
    }
};
