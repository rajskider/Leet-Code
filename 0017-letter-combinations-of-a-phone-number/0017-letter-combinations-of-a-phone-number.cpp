class Solution {
public:
    void solve(vector<string>& ans, string output, int index, string digits, vector<string>& mp) {
        if(index >= digits.length()) {
            ans.push_back(output);
            return;
        }
        int value = digits[index] - '0';
        string temp = mp[value];
        for(int i = 0; i < temp.length(); i++) 
            solve(ans, output + temp[i], index + 1, digits, mp);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(ans, "", 0, digits, mp);
        return ans;
    }
};