class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> temp(26, false);
        for(char c : sentence)
            if(!temp[c - 'a']) temp[c - 'a'] = true;
        for(int i = 0; i < 26; i++)
            if(!temp[i]) return false;
        return true;
    }
};