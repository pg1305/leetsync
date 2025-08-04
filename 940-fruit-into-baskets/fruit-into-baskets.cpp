class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int seen[100001] = {};  
        int l = 0, r = 0, maxLen = 0, count = 0;

        while (r < fruits.size()) {
            if (seen[fruits[r]] == 0) count++;
            seen[fruits[r]]++;

            while (count > 2) {
                seen[fruits[l]]--;
                if (seen[fruits[l]] == 0) count--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};