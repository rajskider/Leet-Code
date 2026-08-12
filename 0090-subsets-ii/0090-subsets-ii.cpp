class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& output, int index, vector<int>& nums) {
        ans.push_back(output);
        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i - 1]) continue;
            output.push_back(nums[i]);
            solve(ans, output, i + 1, nums);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans, output, 0, nums);
        return ans;
    }
};