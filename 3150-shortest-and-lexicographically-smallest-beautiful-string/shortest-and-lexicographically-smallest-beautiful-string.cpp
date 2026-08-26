class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        for (int i = k; i <= s.length(); i++) {
            string res = "";

            for (int j = i; j <= s.length(); j++) {
                string t = s.substr(j - i, i);

                if ((res.empty() || t < res) &&
                    ranges::count(t, '1') == k) {
                    res = t;
                }
            }

            if (!res.empty())
                return res;
        }

        return "";
    }
};