class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row = mat.size();
        int result = 0;
        for(int i = 0; i < row; i++)
            result += mat[i][i] + mat[i][row - i - 1];
        if(row % 2 != 0)
            result -= mat[row / 2][row / 2];
        return result;
    }
};