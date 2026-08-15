class Solution {
public:
    bool isSafe(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        int m = board.size(), n = board[0].size();
        return i >= 0 && i < m && j >= 0 && j < n && !visited[i][j] &&
        board[i][j] == word[index];
    }
    bool solve(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        if(index == word.length()) return true;
        visited[i][j] = true;
        // Down
        if(isSafe(board, word, i + 1, j, index, visited)) {
            if(solve(board, word, i + 1, j, index + 1, visited))
                return true;
        }
        // Left
        if(isSafe(board, word, i, j - 1, index, visited)) {
            if(solve(board, word, i, j - 1, index + 1, visited))
                return true;
        }
        // Right
        if(isSafe(board, word, i, j + 1, index, visited)) {
            if(solve(board, word, i, j + 1, index + 1, visited))
                return true;
        }
        // Up
        if(isSafe(board, word, i - 1, j, index, visited)) {
            if(solve(board, word, i - 1, j, index + 1, visited))
                return true;
        }
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(solve(board, word, i, j, 1, visited))
                        return true;
                }
            }
        }
        return false;
    }
};