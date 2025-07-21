class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (i >= 2 && s[i] == s[i - 1] && s[i] == s[i - 2]) {
                continue; // skip 3rd duplicate
            }
            result.push_back(s[i]); // correctly append character
        }
        return result;
    }
};