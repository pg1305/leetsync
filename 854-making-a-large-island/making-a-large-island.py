class Solution:
    def largestIsland(self, grid):
        n = len(grid)
        island_id = 2
        size = {}
        directions = [(1,0), (-1,0), (0,1), (0,-1)]

        def dfs(r, c, id):
            stack = [(r, c)]
            grid[r][c] = id
            area = 1

            while stack:
                x, y = stack.pop()
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1:
                        grid[nx][ny] = id
                        stack.append((nx, ny))
                        area += 1
            return area

        # Label islands
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    size[island_id] = dfs(i, j, island_id)
                    island_id += 1

        # Fix is HERE
        ans = max(size.values()) if size else 0

        # Try flipping zeros
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    seen = set()
                    curr = 1
                    for dx, dy in directions:
                        ni, nj = i + dx, j + dy
                        if 0 <= ni < n and 0 <= nj < n:
                            if grid[ni][nj] > 1 and grid[ni][nj] not in seen:
                                seen.add(grid[ni][nj])
                                curr += size[grid[ni][nj]]
                    ans = max(ans, curr)

        return ans
