class Solution {
public:
    int solve(int n, vector<int>& ans) {
        if(n < 2) return n;
        if(ans[n] != -1) return ans[n];
        return ans[n] = solve(n - 1, ans) + solve(n - 2, ans);
    }
    int fib(int n) {
        vector<int> ans(n + 1, -1);
        return solve(n, ans);
    }
};