class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);
        for(int i = 0; i < word.length(); i++){
            if(islower(word[i])) 
                lower[word[i] - 'a'] = i;
            else{
                if(upper[word[i] - 'A'] == -1) 
                    upper[word[i] - 'A'] = i;
            }
        }
        set<char> temp;
        for(char c : word){
            if(islower(c)) 
                temp.insert(c);
        }
        int count = 0;
        for (char c : temp) {
            if (lower[c - 'a'] < upper[c - 'a'])
                count++;
        }
        return count;
    }
};