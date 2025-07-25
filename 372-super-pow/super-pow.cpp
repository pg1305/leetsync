class Solution {
public:
    int modPow(int a, int k, int mod) {
        int result = 1;
        a %= mod;
        for (int i = 0; i < k; ++i)
            result = (result * a) % mod;
        return result;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        
        int lastDigit = b.back();
        b.pop_back();

        int part1 = modPow(superPow(a, b), 10, 1337);
        int part2 = modPow(a, lastDigit, 1337);

        return (part1 * part2) % 1337;
    }
};
