class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dir = {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0}
        };
        vector<int> opposite = {1, 0, 3, 2};
        vector<vector<int>> roads = {
            {},         // dummy
            {0,1},      // 1 -> Left, Right
            {2,3},      // 2 -> Up, Down
            {0,3},      // 3 -> Left, Down
            {1,3},      // 4 -> Right, Down
            {0,2},      // 5 -> Left, Up
            {1,2}       // 6 -> Right, Up
        };
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        q.push({0, 0});
        vis[0][0] = true;
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            // reached destination
            if(x == m-1 && y == n-1) return true;
            int type = grid[x][y];
            // try all allowed directions
            for(int d : roads[type]) {
                int nx = x + dir[d].first;
                int ny = y + dir[d].second;
                // boundary check
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(vis[nx][ny]) continue;
                int nextType = grid[nx][ny];
                bool ok = false;
                for(int back : roads[nextType]) {
                    if(back == opposite[d]) {
                        ok = true;
                        break;
                    }
                }

                if(ok) {
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }
};