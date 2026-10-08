class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> temp(26, false);
        for(char c : s){
            if(temp[c - 'a'] == true) return c;
            temp[c - 'a'] = true;
        }
        return '\0';
    }
};