class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(string w: words){
            int s = 0;
            for(char ch: w){
                s += weights[ch - 'a'];
            }
            res += 'z' - s % 26;
        }
        return res;
    }
};