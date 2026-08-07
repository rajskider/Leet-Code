class Solution {
public:
    bool isPossible(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j){
            if(s[i] == s[j]) i++, j--;
            else{
                return isPossible(s, i + 1, j) || isPossible(s, i, j - 1);
            }
        }
        return true;
    }
};