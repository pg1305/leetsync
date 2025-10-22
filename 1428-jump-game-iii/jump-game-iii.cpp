class Solution {
public:
    bool p = false;
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int start, vector<int>& arr){
        visited[start] = true;
        if(arr[start] == 0){
            p = true;
            return;
        }
        for(auto u:adj[start]){
            if(visited[u] == false) dfs(adj, visited, u, arr);
        }
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> adj(n + 10);
        for(int i = 0; i < n; i++){
            int x = arr[i] + i;
            int y = i - arr[i];
            if(x < n) adj[i].push_back(x);
            if(y >= 0) adj[i].push_back(y);
        }
        vector<bool>visited(n + 10, false);
        dfs(adj, visited, start, arr);
        return p;
    }
};