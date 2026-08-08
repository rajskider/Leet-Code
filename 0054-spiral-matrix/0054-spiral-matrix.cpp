class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size(), cols = matrix[0].size();
        int top = 0, bot = rows - 1, left = 0, right = cols - 1;
        int count = 0, total = rows * cols;
        while(count < total){
            // Left -> Right
            for(int i = left; i <= right && count < total; i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            // Top -> Bottom
            for(int i = top; i <= bot && count < total; i++){
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            // Right -> Left
            for(int i = right; i >= left && count < total; i--){
                ans.push_back(matrix[bot][i]);
                count++;
            }
            bot--;
            // Bottom -> Top
            for(int i = bot; i >= top && count < total; i--){
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        return ans;
    }
};