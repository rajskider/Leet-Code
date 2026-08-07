class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for(char c : s)
            if(isalnum(c)) ans.push_back(tolower(c));
        for(int i = 0; i < ans.size() / 2; i++)
            if(ans[i] != ans[ans.size() - i - 1]) return false;
        return true;
    }
};