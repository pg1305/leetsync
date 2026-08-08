class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size(), skip = 0;
        vector<int> last(m, -1);
        for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i)
            if (word1[i] == word2[j])
                last[j--] = i;
        vector<int> res;
        for (int i = 0, j = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            }
            else if(skip == 0 && (j == m - 1 || i < last[j + 1])){
                res.push_back(i);
                skip++;j++;
            }
        }
        return res.size() == m ? res : vector<int>(); 
    }
};