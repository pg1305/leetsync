class Solution {
public:
    const int mod = 1000000007;
    int countHomogenous(string s) {
        long long len = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] == s[i - 1]) len++;
            else {
                len = 1;
            }
            ans = (ans + len)% mod;
        }
        return ans;
        
    }
};