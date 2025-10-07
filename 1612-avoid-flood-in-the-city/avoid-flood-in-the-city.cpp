class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res(rains.size(), 1);
        set<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                st.insert(i);
            } else {
                res[i] = -1;
                if (mp.count(rains[i])) {
                    auto it = st.lower_bound(mp[rains[i]]);
                    if (it == st.end()) {
                        return {};
                    }
                    res[*it] = rains[i];
                    st.erase(it);
                }
                mp[rains[i]] = i;
            }
        }
        return res;
    }
};