class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<int> vis(n, false);
        q.emplace(start);
        vis[start] = true;
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            for(const auto& v : {u + arr[u], u - arr[u]}) {
                if(v >= n || v < 0 || vis[v])
                    continue;
                if(arr[v] == 0)
                    return true;
                vis[v] = true;
                q.emplace(v);
            }
        }
        return arr[start] == 0;
    }
};