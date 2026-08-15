class Solution {
public:
    void solve(vector<vector<int>>& ans, int index, vector<int> nums) {
        if(index >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i = index; i < nums.size(); i++) {
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[index], nums[i]);
            solve(ans, index + 1, nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(ans, 0, nums);
        return ans;
    }
};