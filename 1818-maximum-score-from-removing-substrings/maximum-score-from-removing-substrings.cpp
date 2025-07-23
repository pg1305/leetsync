class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x > y)
            return removePairs(s, 'a', 'b', x, y);
        else
            return removePairs(s, 'b', 'a', y, x);
    }

    int removePairs(string s, char first, char second, int highScore, int lowScore) {
        stack<char> st;
        int score = 0;

        // First pass: remove higher-value pair (first+second)
        string intermediate;
        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                score += highScore;
            } else {
                st.push(c);
            }
        }

        while (!st.empty()) {
            intermediate += st.top();
            st.pop();
        }
        reverse(intermediate.begin(), intermediate.end());

        for (char c : intermediate) {
            if (!st.empty() && st.top() == second && c == first) {
                st.pop();
                score += lowScore;
            } else {
                st.push(c);
            }
        }

        return score;
    }
};
