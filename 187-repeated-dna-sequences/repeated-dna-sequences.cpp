class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        vector<string> res;
        int n = s.size();
        for(int i = 0; i + 9 < n; i++){
            string sub = s.substr(i , 10);
            if(seen.count(sub)){
                repeated.insert(sub);
            }else{
                seen.insert(sub);
            }
        }
        for(const string &str: repeated){
            res.push_back(str);
        }
        return res;
    }
};