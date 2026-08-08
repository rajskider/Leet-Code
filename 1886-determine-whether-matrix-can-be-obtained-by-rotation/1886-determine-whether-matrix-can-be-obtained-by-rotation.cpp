class Solution {
public:
    bool sameMatrix(vector<vector<int>>& mat, vector<vector<int>>& target, int rows, int cols){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++)
                if(mat[i][j] != target[i][j]) return false;
        }
        return true;
    }
    bool rotate(vector<vector<int>>& mat, vector<vector<int>>& target, int rows, int cols){
        for(int i = 0; i < rows - 1; i++){
            for(int j = i + 1; j < cols; j++)
                swap(mat[i][j], mat[j][i]);
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols / 2; j++)
                swap(mat[i][j], mat[i][cols - j - 1]);
        }
        return sameMatrix(mat, target, rows, cols);
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int rows = mat.size(), cols = mat[0].size();
        for(int i = 0; i < 4; i++){
            if(rotate(mat, target, rows, cols)) return true;
        }
        return false;
    }
};