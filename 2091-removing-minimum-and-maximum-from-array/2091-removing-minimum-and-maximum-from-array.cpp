class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mx = 0, mn = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[mx]) mx = i;
            if(nums[i] < nums[mn]) mn = i;
        }
        int a = max(mx, mn) + 1;       // delete from left
        int b = n - min(mx, mn);      // delete from right
        int c = min(mx, mn) + 1 + n - max(mx, mn); // both side
        return min({a, b, c});
    }
};