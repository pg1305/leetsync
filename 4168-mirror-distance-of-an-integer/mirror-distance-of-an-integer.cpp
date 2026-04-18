class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        return abs(n - stoi(string(s.rbegin(), s.rend())));
    }
};