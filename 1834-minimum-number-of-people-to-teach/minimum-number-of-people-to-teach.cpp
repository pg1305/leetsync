class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        vector<unordered_set<int>> knows(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                knows[i + 1].insert(lang); 
            }
        }
        
        unordered_set<int> problematicUsers;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                problematicUsers.insert(u);
                problematicUsers.insert(v);
            }
        }
        
        if (problematicUsers.empty()) return 0;
        
        map<int, int> langCount;
        for (int user : problematicUsers) {
            for (int lang : knows[user]) {
                langCount[lang]++;
            }
        }
        
        int maxKnown = 0;
        for (auto &p : langCount) {
            maxKnown = max(maxKnown, p.second);
        }
        
        return (int)problematicUsers.size() - maxKnown;
    }
};
