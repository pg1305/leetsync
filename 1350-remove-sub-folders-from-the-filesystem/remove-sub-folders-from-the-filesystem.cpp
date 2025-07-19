class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        for(const string&path : folder){
        if (result.empty() || path.substr(0, result.back().size() + 1) != result.back() + "/") {
            result.push_back(path);
        }

        }
        return result;
    }
};