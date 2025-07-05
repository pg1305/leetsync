class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while ((int)word.size() < k) {
            string temp = "";
            for (char c : word) {
                temp += (c == 'z') ? 'a' : c + 1;
            }
            word += temp;
        }
        return word[k - 1];
    }
};
