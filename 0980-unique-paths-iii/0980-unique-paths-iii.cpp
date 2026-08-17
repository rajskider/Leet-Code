class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int endx, int endy, int x, int y,
    vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        return x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] &&
        grid[x][y] != -1;
    }
    void solve(int& count, vector<vector<int>>& grid, int x, int y,
    int endx, int endy, vector<vector<bool>>& visited, int remaining) {
        if(x == endx && y == endy) {
            if(remaining == 1) count++;
            return;
        }
        visited[x][y] = true;
        // Down
        if(isSafe(grid, endx, endy, x + 1, y, visited))
            solve(count, grid, x + 1, y, endx, endy, visited, remaining - 1);
        // Left
        if(isSafe(grid, endx, endy, x, y - 1, visited))
            solve(count, grid, x, y - 1, endx, endy, visited, remaining - 1);
        // Right
        if(isSafe(grid, endx, endy, x, y + 1, visited))
            solve(count, grid, x, y + 1, endx, endy, visited, remaining - 1);
        // Up
        if(isSafe(grid, endx, endy, x - 1, y, visited))
            solve(count, grid, x - 1, y, endx, endy, visited, remaining - 1);
        visited[x][y] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0, startx = -1, starty = -1, endx = -1, endy = -1;
        int remaining = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != -1) remaining++;
                if(grid[i][j] == 1) {
                    startx = i;
                    starty = j;
                }
                if(grid[i][j] == 2) {
                    endx = i;
                    endy = j;
                }
            }
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        solve(count, grid, startx, starty, endx, endy, visited, remaining);
        return count;
    }
};