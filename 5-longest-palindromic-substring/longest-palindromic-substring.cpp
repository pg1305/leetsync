class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        // Step 1: Transform the string to handle even/odd length palindromes easily
        // Example: "babad" -> "^#b#a#b#a#d#$"
        // We use '^' and '$' at the ends so we don't have to write bounds-checking logic inside the while loop.
        string t = "^";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";
        
        int n = t.length();
        
        // p[i] will store the radius of the longest palindrome centered at index i
        vector<int> p(n, 0); 
        
        int C = 0; // The center of the palindrome that reaches furthest to the right
        int R = 0; // The rightmost boundary of that palindrome
        
        int maxLen = 0;
        int centerIndex = 0;
        
        // Step 2: Calculate the palindrome radii
        for (int i = 1; i < n - 1; i++) {
            // Find the mirror index of 'i' around center 'C'
            int mirror = 2 * C - i; 
            
            // If 'i' is within the right boundary, we can copy the radius from the mirror
            if (R > i) {
                p[i] = min(R - i, p[mirror]);
            }
            
            // Expand the palindrome centered at 'i' (The expanding step)
            // Because of our '^' and '$' guards, this loop will naturally stop at the edges
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
                p[i]++;
            }
            
            // If the palindrome centered at 'i' expands past our current right boundary, update C and R
            if (i + p[i] > R) {
                C = i;
                R = i + p[i];
            }
            
            // Track the absolute maximum length and its center to extract the answer later
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }
        
        // Step 3: Extract the original string
        // The start index in the original string requires some math to strip out the '#' markers
        int start = (centerIndex - 1 - maxLen) / 2;
        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};