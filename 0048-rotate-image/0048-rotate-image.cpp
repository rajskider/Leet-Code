class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        // Transpose
        for(int i = 0; i < rows - 1; i++){
            for(int j = i + 1; j < cols; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        // Reverse every row
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols / 2; j++)
                swap(matrix[i][j], matrix[i][cols - j - 1]);
        }
    }
};