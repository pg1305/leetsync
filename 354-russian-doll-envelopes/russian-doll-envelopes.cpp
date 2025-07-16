class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n==0) return 0;
        vector<pair<int,int>> envelop(n);
        for(int i = 0; i < n; i++){
            envelop[i].first = envelopes[i][0];
            envelop[i].second = envelopes[i][1];
        }
        int count = 1;
        sort(envelop.begin(),envelop.end(),[](pair<int,int> &a,pair<int,int> &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        vector<int> dp;
        for(int i = 0; i < n; i++){
            int height = envelop[i].second;
            auto it = lower_bound(dp.begin(),dp.end(),height);
            if(it == dp.end()) dp.push_back(height);
            else*it = height;
        }
        return dp.size();
        
        
    }
};